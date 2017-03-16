T = int(raw_input())

vowels = ['a', 'e', 'i', 'o', 'u']

for case in xrange(1, T+1):
  s = raw_input().split(' ')
  L = s[0]
  n = int(s[1])
  n_val = 0
  # get a list of all substrings of length n
  begin = 0
  end = 0
  sbstr = []
  for i, c in enumerate(L):
    if c not in vowels:
      end = i
      if end - begin + 1 == n:
        sbstr.append([begin, end])
        begin = begin + 1
    else:
      begin = i + 1
      end = i + 1
  checked = []
  # print 'Substings: ', sbstr
  for sb in sbstr:
    for i in range(sb[0], -1, -1):
      for j in range(sb[1], len(L)):
        # print [i, j]
        if [i, j] not in checked:
          checked.append([i, j])
    # print checked
  # print 'N:', len(checked)
  print 'Case #{0}: {1}'.format(case, len(checked))