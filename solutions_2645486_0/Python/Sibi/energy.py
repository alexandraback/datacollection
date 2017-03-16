def getGainOfInterval(interval,start,final,R,E):
  n = len(interval)
  maxVal = max(interval)
  maxPos = interval.index(maxVal)+1
  leftPossibleE = start+(maxPos-1)*R
  rightPossibleE = min(leftPossibleE,E)-(final-(n-maxPos+1)*R)
  possibleE = min([leftPossibleE,rightPossibleE,E])
  possibleE = max(possibleE,0)
  myGain = possibleE * maxVal
  
  if leftPossibleE <= E:
    if rightPossibleE <= E:
      return myGain
    else:
      return myGain + getGainOfInterval(interval[maxPos:],R,final,R,E)
  else:
    if rightPossibleE <= E:
      return myGain + getGainOfInterval(interval[:(maxPos-1)],start,E,R,E)
    else:
      return myGain + getGainOfInterval(interval[:(maxPos-1)],start,E,R,E) + getGainOfInterval(interval[maxPos:],R,final,R,E)

iFile = open("B-small-attempt2.in","r")
oFile = open("output.txt","w")

cases = int(iFile.readline().strip())

for case in range(cases):
  
  line = iFile.readline().strip().split()
  E = int(line[0])
  R = int(line[1])
  schedule = [int(a) for a in iFile.readline().strip().split()]

  gain = getGainOfInterval(schedule,E,R,R,E)

  output = str(gain)
  
  oFile.write("Case #"+str(case+1)+": "+output+"\n")
