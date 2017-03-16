num_cases = int(raw_input())
for case_id in range(1, num_cases + 1):
  n = int(raw_input())
  if n == 0:
    print('Case #%d: INSOMNIA' % case_id)
    continue
  seen = 10 * [ False ]
  seen_count = 0
  x = 0
  while seen_count != 10:
    x += n
    y = x 
    while y != 0:
      d = y % 10
      if not seen[d]:
        seen[d] = True
        seen_count += 1
      y //= 10
  print('Case #%d: %d' % (case_id, x))
