import sys


def get_number_of_tests(fd):
  ''' get the number of tests. '''
  n = fd.readline()
  return int(n)


def successor(value, sorted_list):
  ''' search the successor in sorted_list, given [start_index, end_index) '''
  start_index = 0
  end_index = len(sorted_list)
  while end_index > start_index:
    middle_index = (end_index + start_index) / 2
    if value > sorted_list[middle_index]:
      start_index = middle_index + 1
    elif value < sorted_list[middle_index]:
      end_index = middle_index
    else:
      assert False
  assert start_index == end_index
  if start_index == len(sorted_list):
    return None
  return start_index


def deceitful_war_scores(naomi, ken):
  ''' scores that naomi will get if playing deceitful war. '''
  naomi_scores = 0
  ken.reverse()
  for k in ken:
    n = successor(k, naomi)
    if n is not None:
      naomi_scores += 1
      naomi.pop(n)
    else:
      naomi.pop(0)
  return naomi_scores


def war_scores(naomi, ken):
  ''' scores that naomi will get if playing war. '''
  ken_scores = 0
  for n in naomi:
    k = successor(n, ken)
    if k is not None:
      ken_scores += 1
      ken.pop(k)
    else:
      ken.pop(0)
  return len(naomi) - ken_scores


def main(fd):
  n = get_number_of_tests(fd)
  for i in xrange(n):
    fd.readline()
    naomi = map(float, fd.readline().strip().split())
    ken = map(float, fd.readline().strip().split())
    naomi.sort()
    ken.sort()
    print 'Case #%d: %d %d' % (i + 1, deceitful_war_scores(naomi[:], ken[:]), war_scores(naomi[:], ken[:]))


if __name__ == '__main__':
  main(sys.stdin)
