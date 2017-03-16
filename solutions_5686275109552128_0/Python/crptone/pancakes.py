from math import ceil

f = open('pancakes.txt', 'r')
#f = open('D-large.in', 'r')
g = open('pancakes.out', 'w')
lines = int(f.readline())
count = 1

times = {1: (1, 0), 2: (2, 0), 3: (3, 0)}#, 4: (3, 1), 5: (4, 1), 6: (4, 1), 7: (5, 1), 8: (5, 2)}

def stacktime(n):
  if n in times:
    return times[n]
  else:
    a = ceil(n/2)
    b = n - a
    print(n, a, b)
    sa = stacktime(a)
    sb = stacktime(b)
    time = (max(sa[0],sb[0]) + sa[1] + 1, sa[1] + 1)
    times[n] = time
    return time

while count <= lines:
  n = int(f.readline())
  diners = [int(i) for i in f.readline().strip().split()]
  print(diners)
  g.write('Case #' + str(count) + ': ' + ('GABRIEL' if True else 'RICHARD') + '\n')
  count += 1

f.close()
g.close()
