fin = open('input.txt', 'rb')
fout = open('output.txt', 'wb')

n = int(fin.readline()[:-1])

words = [('ZERO', 0), ('TWO', 2), ('EIGHT', 8), ('FOUR', 4), ('FIVE', 5), ('SIX', 6),
         ('ONE', 1),  ('THREE', 3), ('SEVEN', 7), ('NINE', 9)]
for i in xrange(n):
  s = fin.readline()[:-1]
  counts = {chr(ch): s.count(chr(ch)) for ch in xrange(ord('A'), ord('Z') + 1)}
  ans = []
  for word, num in words:
    val = 10 ** 7
    for ch in xrange(ord('A'), ord('Z') + 1):
      ch = chr(ch)
      if word.count(ch) > 0:
        val = min(val, counts[ch] / word.count(ch))

    ans += [num] * val
    for ch in xrange(ord('A'), ord('Z') + 1):
      ch = chr(ch)
      if word.count(ch) > 0:
        counts[ch] -= word.count(ch) * val;

  ans = sorted(ans)
  fout.write('Case #{}: '.format(i + 1))
  for num in ans:
    fout.write(str(num))
  fout.write('\n')

  print counts
