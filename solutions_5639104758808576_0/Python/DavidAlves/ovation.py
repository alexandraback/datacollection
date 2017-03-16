T = int(raw_input())

for t in xrange(1, T+1):
   _, arr = raw_input().split()
   arr = map(int, arr)
   standing = 0
   res = 0
   for i, count in enumerate(arr):
       if standing < i and count > 0:
           res += i - standing
           standing = i
       standing += count
   print("Case #{}: {}".format(t, res))
