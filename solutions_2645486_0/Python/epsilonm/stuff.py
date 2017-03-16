cases = int(raw_input())


def do(maxe, gain, quant, vals):
  d={}
  def max_gain(current, index):
    if index == quant:
      return 0
    key = (current, index)
    if key in d:
      return d[key]
    ans = max(i*vals[index] + max_gain(min(maxe, current-i+gain), index+1) for i in xrange(current+1))
    d[key] = ans
    return ans

  return max_gain(maxe, 0) 



for case in xrange(1,cases+1):
  maxe, gain, quant = map(int, raw_input().split(' '))
  vals = map(int, raw_input().split(' '))

  ans = do(maxe, gain, quant, vals)


  print 'Case #%d: %s' % (case, str(ans))