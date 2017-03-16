
def fun(size, sizes):
  cache = {}
  def do(size, sizes, pointer=0, ops=0):
    if (size, pointer) in cache:
      return cache[(size, pointer)]
    temppointer = pointer
    if not sizes:
      return 0
    if size == 1:
      return len(sizes)
    while pointer < len(sizes):
      if sizes[pointer] < size:
        size += sizes[pointer]
        pointer += 1
      elif size +size -1 > sizes[pointer]:
        size += size -1 + sizes[pointer]
        pointer += 1
        ops += 1
      else:
        res1 = do(size, sizes, pointer+1, ops+1)
        res2 = do(size + (size-1), sizes, pointer, ops+1)
        r= min(res1, res2)
        cache[(size,temppointer)] = r
        return r

    return ops
  return do(size, sizes)


tests = int(raw_input())

for case in xrange(1, tests+1):
  size,_ = map(int, raw_input().split(' '))
  sizes = map(int, raw_input().split(' '))
  sizes.sort()
  res = fun(size, sizes)
  print 'Case #%d: %d' %(case,res)

