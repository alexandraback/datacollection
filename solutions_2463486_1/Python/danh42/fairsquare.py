import sys

paldig=[[str(i) for i in range(1,10)], [str(i) for i in [11,22,33,44,55,66,77,88,99]]]

maxdigits=14

def ispal(s):
   return s==s[::-1]

for i in range(3, maxdigits//2+1):
   small = paldig[i-2]
   larger=[]
   for s in small:
      for c in '0123456789':
         larger.append(c + s + c)
   paldig.append(larger)

allfands=[]

for i in range(len(paldig)):
   for v in paldig[i]:
      if v[0] != '0':
         vi=int(v)
         v2s = str(vi*vi)
         if len(v2s) > maxdigits: 
            break
         if ispal(v2s):
            allfands.append(vi*vi)

inlines = open(sys.argv[1], 'r').readlines()
T=int(inlines[0])
for i in range(T):
   A,B = [int(x) for x in inlines[i+1].split()]
   res=len([x for x in allfands if x>=A and x<=B])
   print('Case #{0}: {1}'.format(i+1,res))
