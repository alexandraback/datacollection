def do(size, sizes, pointer=0, ops=0):
  if not sizes:
    return 0
  if size == 1:
    return len(sizes)
  while pointer < len(sizes):
    if sizes[pointer] < size:
      size += sizes[pointer]
      pointer += 1
    else:
      res1 = do(size, sizes, pointer+1, ops+1)
      res2 = do(size + (size-1), sizes, pointer, ops+1)
      return min(res1, res2)

  return ops


tests = int(raw_input())

for case in xrange(1, tests+1):
  size,_ = map(int, raw_input().split(' '))
  sizes = map(int, raw_input().split(' '))
  sizes.sort()
  res = do(size, sizes)
  print 'Case #%d: %d' %(case,res)

