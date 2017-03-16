f = open('A-large.in','r') 
n = int(f.readline()) 
for k in range(n):
  st = f.readline() 
  ans = '' 
  for i in st[:-1]:
    if ans == '': ans+= i 
    else:
      if ord(i) >= ord(ans[0]): ans = i+ans 
      else: ans = ans+i 
  print 'Case #'+str(k+1)+': '+ans
      
