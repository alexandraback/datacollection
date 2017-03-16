num_cases = int(raw_input())
for case_index in range(1, num_cases + 1):
  s, t = raw_input().split()
  n = len(s)
  format = '%0' + str(n) + 'd'
  s_digits = list(s)
  t_digits = list(t)
  best_difference, best_s_value, best_t_value = 10 ** n, None, None
  for x in range(10 ** n):
    xs = format % x
    feasible = True
    for i in range(n):
      if s[i] == '?':
        s_digits[i] = xs[i]
      elif s_digits[i] != xs[i]:
        feasible = False
    if not feasible:
      continue
    s_value = int(''.join(s_digits))
    for y in range(10 ** n):
      ys = format % y
      feasible = True
      for i in range(n):
        if t[i] == '?':
          t_digits[i] = ys[i]
        elif t_digits[i] != ys[i]:
          feasible = False
      if not feasible:
        continue
      t_value = int(''.join(t_digits))
      difference = abs(s_value - t_value)
      if difference > best_difference:
        continue
      if difference == best_difference:
        if s_value > best_s_value:
          continue
        if s_value == best_s_value:
          if t_value > best_t_value:
            continue
      best_difference = difference
      best_s_value, best_t_value = s_value, t_value
  print('Case #%d: %s %s' % (case_index, format % best_s_value,
      format % best_t_value))
