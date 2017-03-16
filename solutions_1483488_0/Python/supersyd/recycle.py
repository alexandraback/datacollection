
f = open('C-small-attempt0.in')
txt = f.read()
f.close()

txt = txt.strip().split('\n')

t = int(txt[0])
txt = txt[1:]

s = "" 
for i in range(t):
  nums = txt[i].split()
  a = int(nums[0])
  b = int(nums[1])
  r = 0
  for j in range(a,b+1):
    checked = set([]) 
    n = str(j)
    m = n 
    for k in range(len(n)-1):
      m = m[1:] + m[0]
      if int(m) <= int(n): continue 
      if int(m) <= b and (n,m) not in checked:
        r += 1
        checked.add((n,m))
  s += "Case #"+str(i+1)+": "+str(r)+"\n"
print s

f = open('out','w')
f.write(s)
f.close()

