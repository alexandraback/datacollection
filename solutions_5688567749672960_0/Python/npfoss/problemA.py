def howmany(n):
   if n <= 20:
      return n
   sn = str(n)
   digets = len(sn)
   nums = numsToGetTo10(digets-1)
   sh = sn[digets//2:]
   print(sh)
   fh = sn[:digets//2]
   print(fh[::-1])
   nums += int(sh)
   nums += int(fh[::-1]) - 1 + needToFlip(fh)
   return nums

def needToFlip(s):
   if s[0] == '1':
      for i in range(1,len(s)):
         if s[i] != '0':
            return True
   else: return True
   return False
   
def numsToGetTo10(p):
   # p = power of 10 to get to
   if not p in pows:
      s = int('9'*((p+1)//2))
      s += int('9'*(p//2))
      pows[p] = s + numsToGetTo10(p-1) + 1
   return pows[p]

file = open('A-small-attempt1.in', 'r') # A-small-attempt0.in
out = open('outputA.txt', 'w')

pows = {1:10,2:29,3:138,4:337}

num = int(file.readline().strip())
for x in range(num):
   n = int(file.readline().strip())
   out.write('Case #'+str(x+1)+': ' + str(howmany(n)) + '\n')
   print('done with %2d'%x)

file.close()
out.close()