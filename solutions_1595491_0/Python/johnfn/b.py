lines = [l[:-1] for l in open("in4")][1:]

highest_normal_score_for = [0] * 31
highest_surprising_score_for = [0] * 31

#memoize everything!!!
for x in range(11):
  for y in range(11):
    for z in range(11):
      if abs(x-y) > 2 or abs(y-z) > 2 or abs(z-x) > 2:
        continue
      if abs(x-y) == 2 or abs(y-z) == 2 or abs(z-x) == 2:
        highest_surprising_score_for[x+y+z] = max(max(x,y,z), highest_surprising_score_for[x+y+z])
      else:
        highest_normal_score_for[x+y+z] = max(max(x,y,z), highest_normal_score_for[x+y+z])

for i, l in enumerate(lines):
  print "Case #%d:" % (i+1),
  nums = [int(x) for x in l.split(" ")]
  _, surprises, threshold = nums[:3]
  over_highest = 0

  scores = sorted(nums[3:], reverse=True)
  for s in scores:
    if highest_normal_score_for[s] >= threshold:
      over_highest += 1
    elif highest_surprising_score_for[s] >= threshold and surprises > 0:
      surprises -= 1
      over_highest += 1

  print over_highest

