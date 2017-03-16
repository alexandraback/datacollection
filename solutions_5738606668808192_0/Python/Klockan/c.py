raw_input()
n,j=map(int,raw_input().split())
print "Case #1:"
for x in range(j):
  ans="1"
  for i in range(1,n-1,2):
    ans+="11"if x&1 else"00"
    x/=2
  print ans+"1","3 4 5 6 7 8 9 10 11"
