import string

testIndex=1

problemRoot="d:/prog/versenyek/googlejam"
problemDir="2015/quali"
inputFiles= ["D_example.in",  "D-small.in",  "D-large.in"]
outputFiles=["D_example.out", "D-small.out", "D-large.out"]

fileName=string.strip(problemRoot)+"/"+problemDir+"/"+inputFiles[testIndex]
inputData=[map(int, line.split()) for line in open(fileName,'r') if line.strip()]
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+outputFiles[testIndex]
fileToWrite=open(fileName,'w')
for iCase in range(int(inputData[0][0])):
  x,r,c=inputData[iCase+1]
  if (r*c)%x!=0: # there is no such fill at all:
    fileToWrite.write("Case #"+str(iCase+1)+": RICHARD\n")
  elif x>max(r,c): # Richard gives the x-by-1 piece
    fileToWrite.write("Case #"+str(iCase+1)+": RICHARD\n")
  elif x>2*min(r,c): # Richard gives the big L with (at least) min(r,c)+1 length in each direction
    fileToWrite.write("Case #"+str(iCase+1)+": RICHARD\n")
  elif x>=r+c: # Richard gives the big L with max(r,c) and the rest (the other +1, at least) lengths
    fileToWrite.write("Case #"+str(iCase+1)+": RICHARD\n")
  elif x>=7: # Richard can give a tile with a hole in it which is impossible to fill
    fileToWrite.write("Case #"+str(iCase+1)+": RICHARD\n")
  else: # Richard was unable to give a single item which doesn't fit or makes inpossible to end the game
    if x==1 or x==2: # there is always a solution for 1-by-1s, and also for 1-by-2s if r*c is even
      fileToWrite.write("Case #"+str(iCase+1)+": GABRIEL\n")
    elif x==3: # 3|r*c and r,c>1 => use two of the given shape, form a 2-by-3 and put the longer side parallel to the side is multiple of 3
      fileToWrite.write("Case #"+str(iCase+1)+": GABRIEL\n")
    elif x==4: # r,c>=2
      if r==2 or c==2: # Richard can give the T which divides the shape to 2 odd parts
        fileToWrite.write("Case #"+str(iCase+1)+": RICHARD\n")
      else: # 2xT+L, 2xL+Z, 2xsquare+I form 3x4 and r*c is at least 3x4 by now, and ... the rest is always fillable
        fileToWrite.write("Case #"+str(iCase+1)+": GABRIEL\n")
    elif x==5: # r,c>=3
      if r==3 or c==3:
        if r*c<30: # W can't be placed so that both remainer are dividable by 5
          fileToWrite.write("Case #"+str(iCase+1)+": RICHARD\n")
        else:
          fileToWrite.write("Case #"+str(iCase+1)+": GABRIEL\n")
      else: # all pieces are part of a 4x5 grid which can be extended as needed
        fileToWrite.write("Case #"+str(iCase+1)+": GABRIEL\n")
    elif x==6: # r,c>=4, each hexominio fits in 3x6 so that the remainer is connected, that means it all of them fit in a 4x6 with 3 others
      fileToWrite.write("Case #"+str(iCase+1)+": GABRIEL\n")
fileToWrite.close()
