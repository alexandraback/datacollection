import sys

out_file = sys.stdout

num_cases = int(raw_input())
for case_id in range(1, num_cases + 1):
  out_file.write('Case #%d:' % case_id)
  k, c, s = map(int, raw_input().split())
  if s * c < k:
    out_file.write(' IMPOSSIBLE\n')
    continue
  k_pos = 0
  while k_pos < k:
    span = k ** c
    pos = 0
    for i in range(c):
      span //= k
      pos += k_pos * span
      k_pos += 1
      if k_pos == k:
        break
    out_file.write(' ' + str(pos + 1))
  out_file.write('\n')
