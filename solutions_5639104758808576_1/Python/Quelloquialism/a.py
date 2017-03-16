T = input()
for tc in range(1, T + 1):
  clap = 0
  friend = 0
  dudes = raw_input().split(" ")[1]
  for i in range(len(dudes)):
    if clap < i:
      friend += 1
      clap += 1
    clap += int(dudes[i])
  print "Case #" + str(tc) + ":", friend
