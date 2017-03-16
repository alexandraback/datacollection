import sys,operator
data = sys.stdin.readlines()
c=1
i=1

while (i<len(data)):
  A = int(data[i].strip())
  i+=1
  nums = []
  for j in xrange(A):
    nums.append(map(int,data[i].strip().split()))
    i+=1
  nums.sort()
  stars = 0
  count = 0
  change = 1
  while (change):
    change = 0
    removed = 1
    ##print count,nums
    while (removed):
      removed = 0
      newnums = []
      for pair in nums:
        #go through and do any 2 stars we can
        if (pair[1]<=stars):
          change = 1
          count+=1
          if (pair[0] != -1):stars+=1
          stars+=1
          removed = 1
          #print "removed %s"%pair
        else:
          newnums.append(pair)
      nums = newnums
    r = -1
    for j in xrange(len(nums)):
      if (nums[j][0] != -1 and nums[j][0] <= stars):
        if r == -1:r = j
        else:
          if nums[j][1] >= nums[r][1]:r = j

    if r != -1:
      #print nums[r]
      change = 1
      count+=1
      stars +=1
      nums[r][0] = -1


  if nums:
    print "Case #%s: Too Bad"%c
  else:
    print "Case #%s: %s"%(c,count)
  c+=1