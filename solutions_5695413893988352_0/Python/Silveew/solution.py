
def read_int(): return int(raw_input())
def read_pair_list(): return [(int(pair.split(',')[0]), int(pair.split(',')[1])) for pair in raw_input().split()]
def read_int_list(): return [int(x) for x in raw_input().split()]
def read_pair(): return [int(x) for x in raw_input().strip().split(',')]
def read_string(): return raw_input().strip()


def parse_input():
  T = read_int()
  cases = []
  for _ in xrange(T):
    s1, s2 = read_string().strip().split()
    s1 = [int(c) if c!='?' else -1 for c in s1]
    s2 = [int(c) if c!='?' else -1 for c in s2]
    cases.append((s1, s2))
  return cases


def combine(digits, base):
    number = 0
    for digit in digits:
        number *= base
        number += digit
    return number


def combine_digits(d):
    return combine(d, 10)


def solve_case(case):
  s1, s2 = case
  s1_orig = s1[:]
  s2_orig = s2[:]
  # look for first difference
  for i in xrange(len(s1)):
    if s1[i] != -1 and s2[i] != -1 and s1[i] != s2[i]:
      break

  # if there is no such point
  if not (s1[i] != -1 and s2[i] != -1 and s1[i] != s2[i]):
    i += 1

  # everyhing up untill that point needs to be the same
  for j in xrange(i):
    if s1[j] == -1 and s2[j] >= 0:
      s1[j] = s2[j]
    elif s1[j] >= 0 and s2[j] == -1:
      s2[j] = s1[j]
    elif s1[j] >= 0 and s2[j] >= 0:
      pass
    else:
      s1[j] = 0
      s2[j] = 0

  # everything after this point is minmaxed
  if i < len(s1):
    if s1[i] > s2[i]:
      for j in xrange(i+1, len(s1)):
        if s1[j] == -1:
          s1[j] = 0
        if s2[j] == -1:
          s2[j] = 9
    else:
      for j in xrange(i+1, len(s1)):
        if s2[j] == -1:
          s2[j] = 0
        if s1[j] == -1:
          s1[j] = 9

  opt1_s1 = s1[:]
  opt1_s2 = s2[:]

  # two options
  # maybe one needs to be incremented or decremented
  inc_succ = False
  dec_succ = False
  opt2_s1 = s1[:]
  opt2_s2 = s2[:]
  opt3_s1 = s1[:]
  opt3_s2 = s2[:]
  opt4_s1 = s1[:]
  opt4_s2 = s2[:]
  opt5_s1 = s1[:]
  opt5_s2 = s2[:]
  if i < len(s1):
    # also try increment s2
    j = i-1
    while not inc_succ and j >= 0:
      if s2_orig[j] == -1:
        opt2_s2[j] += 1
        if opt2_s2[j] < 10:
          inc_succ = True
        else:
          opt2_s2[j] = 0
          j = j -1
          if j < 0:
            break
      else:
        j = j - 1
    # also try decrement s1
    j = i-1
    while not dec_succ and j >= 0:
      if s1_orig[j] == -1:
        opt3_s1[j] -= 1
        if opt3_s1[j] > -1:
          dec_succ = True
        else:
          opt3_s1[j] = 9
          j = j -1
          if j < 0:
            break
      else:
        j = j - 1


  inc_succ = False
  dec_succ = False
  if i < len(s1):
    # also try increment s1
    j = i-1
    while not dec_succ and j >= 0:
      if s1_orig[j] == -1:
        opt4_s1[j] += 1
        if opt4_s1[j] < 10:
          inc_succ = True
        else:
          opt4_s1[j] = 0
          j = j -1
          if j < 0:
            break
      else:
        j = j - 1
    # also try decrement s2
    j = i-1
    while not dec_succ and j >= 0:
      if s2_orig[j] == -1:
        opt5_s2[j] -= 1
        if opt5_s2[j] > -1:
          dec_succ = True
        else:
          opt5_s2[j] = 9
          j = j -1
          if j < 0:
            break
      else:
        j = j - 1


  def all_options(s):
    if not s:
      return [[]]
    if s[0] == -1:
      return [[x] + o for x in range(10) for o in all_options(s[1:])]
    else:
      return [[s[0]] + o for o in all_options(s[1:])]

  brute_s1 = all_options(s1)
  brute_s2 = all_options(s2)
  brute_pairs = [(a, b) for a in brute_s1 for b in brute_s2]

  options_ints = [
      (combine_digits(o1), combine_digits(o2)) for o1, o2 in brute_pairs]
  diffs = [abs(x1-x2) for x1, x2 in options_ints]
  sums = [x1 + x2 for x1, x2 in options_ints]

  min_diff = min(diffs)

  # only keep the options with minimal difference
  min_options = []
  min_options_sums = []
  for o, d, s in zip(brute_pairs, diffs, sums):
    if d == min_diff:
      min_options.append(o)
      min_options_sums.append(s)

  min_sum = min(min_options_sums)

  for o, s in zip(min_options, min_options_sums):
    if s == min_sum:
      res = o
      break

  return res



  if True:
    # determine which solution was best
    options = [
      (opt1_s1, opt1_s2),
      (opt2_s1, opt2_s2),
      (opt3_s1, opt3_s2),
      (opt4_s1, opt4_s2),
      (opt5_s1, opt5_s2),
    ]
    options_ints = [
      (combine_digits(o1), combine_digits(o2)) for o1, o2 in options]
    diffs = [abs(x1-x2) for x1, x2 in options_ints]
    sums = [x1 + x2 for x1, x2 in options_ints]

    min_diff = min(diffs)

    # only keep the options with minimal difference
    min_options = []
    min_options_sums = []
    for o, d, s in zip(options, diffs, sums):
      if d == min_diff:
        min_options.append(o)
        min_options_sums.append(s)

    min_sum = min(min_options_sums)

    for o, s in zip(min_options, min_options_sums):
      if s == min_sum:
        return o


if __name__ == '__main__':
  for idx, args in enumerate(parse_input()):
    res = solve_case(args)
    s1 = ''.join(map(str, res[0]))
    s2 = ''.join(map(str, res[1]))

    print 'Case #%d:' % (idx + 1), s1, s2
