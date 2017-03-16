import sys
r = None
t = None


def works(m):
  global r
  global t
  Sm = m*(2*r-1) + 2*m*m;
  return Sm <= t


data = sys.stdin.readlines()
T = int(data[0])

for cs in range(1, T+1):
  sp = data[cs].split()
  r = int(sp[0])
  t = int(sp[1])

  l = 1
  h = t
  while l <= h:
    m = (l+h) / 2
    if works(m):
      l = m + 1
    else:
      h = m -1;
  res = l - 1

  print 'Case #' + str(cs) + ': ' + str(res)
#     while (l <= h) {
#       m = (l+h) / 2;
#       if(works(m)) {
#         l=m+1;
#       } else {
#         h=m-1;
#       }
#     }
#     LL res = l-1;
#     cout << res << endl;
#   }
#   return 0;
# }
