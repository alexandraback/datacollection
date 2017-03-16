def sort(list):
  l=list[:]
  indices=range(len(l))
  for i in range(len(l)):
    for j in range(len(l)-1):
      if l[j]>l[j+1]:
        tmp=l[j]
        l[j]=l[j+1]
        l[j+1]=l[j]
        tmp=indices[j]
        indices[j]=indices[j+1]
        indices[j+1]=tmp
  return indices

def f2(x,s):
  if x[0] in s or x[1] in s:
    return True

def conprep(order, frontier, x,f):
  cit=citiesf(order,frontier,x)
  x= connected(cit, flightsf(cit,f))
  return x

def connected(cities,flights):
  c=set(cities)
  f=flights[:]
  r=len(c)
  can={c.pop()}
  for j in range(r):
    for i in filter(lambda x: f2(x,can), f):
      can.add(i[0])
      can.add(i[1])
      c.discard(i[0])
      c.discard(i[1])
  return len(can)==r

def citiesf(c,f,x):
  c2=c[:]
  for i in f:
    if i==x:
      c2.append(i)
      return c2
    else:
      c2.append(i)
  return -1

def flightsf(c,f):
  return filter(lambda x: x[0] in c and x[1] in c, f)

def answer(c,f):
  order=sort(c)
  frontier=[order[0]]
  out=str(c[order[0]])
  order=order[1:]
  while len(order)>0:
    cand = []
    for i in order:
      cand+=map(lambda x: (x,i), filter(lambda x: [i,x] in f or [x,i] in f, frontier[::-1]))
    cand=filter(lambda x: conprep(order,frontier,x[0],f), cand)
    out+=str(c[cand[0][1]])
    order.remove(cand[0][1])
    frontier=frontier[:frontier.index(cand[0][0])+1]+[cand[0][1]]
  return out

with open('/home/gauravjs/Documents/Google Code Jam/20141B/input3s','r') as f:
  cases=int(f.readline())

  for i in range(cases):
    c,fl=map(int, f.readline().strip().split(" "))
    cities=[]
    for j in range(c):
      cities.append(int(f.readline()))
    flights=[]
    for j in range(fl):
      flights.append(map(lambda x: int(x)-1, f.readline().strip().split(" ")))
    s=answer(cities,flights)
    
    print 'Case #'+str((i+1))+':',s
