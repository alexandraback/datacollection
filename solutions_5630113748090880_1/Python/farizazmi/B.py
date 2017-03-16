fin = open('B-large.in', 'r')
fout = open('B-large.out', 'w')
for tc in range(1, int(fin.readline()) + 1):
  n = int(fin.readline())
  h = [0] * 2501
  for i in range(2 * n - 1):
    a = map(int, fin.readline().split())
    for b in a:
      h[b] = (h[b] + 1) % 2
  res = ''
  for i in range(2501):
    if h[i] == 1:
      res += ' ' + str(i)
  fout.write('Case #' + str(tc) + ':' + str(res) + '\n')
fin.close()
fout.close()
