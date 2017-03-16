num_cases = int(raw_input())
for case_id in range(1, num_cases + 1):
  s = raw_input().strip()
  result = 0
  for i in range(1, len(s)):
    if s[i - 1] != s[i]:
      result += 1
  if s[-1] == '-':
    result += 1
  print('Case #%d: %d' % (case_id, result))
