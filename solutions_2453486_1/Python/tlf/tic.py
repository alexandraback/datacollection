#! /usr/bin/python
import string


outputList = []
fp = open("input.txt","r")
for caseNo in range(int(fp.readline())):
   boardList = []
   oList = []
   xList = []
   xWin = 0
   oWin = 0
   draw = 0
   for x in range(4):
      boardList.append(fp.readline()[:-1])
      oList.append(boardList[x])
      xList.append(boardList[x])
   #create the X and O boards
   for x in range(4):
      if "T" in oList[x]:
         for y in range(4):
            if oList[x][y] == "T":
               oList[x] = oList[x][:y] + "O" + oList[x][y + 1:]
      if "T" in xList[x]:
         for y in range(4):
            if xList[x][y] == "T":
               xList[x] = xList[x][:y] + "X" + xList[x][y + 1:]
   #check for win
   for x in range(4):
      if oList[x] == "OOOO":
         oWin = 1
      if xList[x] == "XXXX":
         xWin = 1
      culmx = 0
      culmo = 0
      #print xList
      for y in range(4):
         if xList[y][x] == "X":
            culmx += 1
         if oList[y][x] == "O":
            culmo += 1
      if culmx == 4:
         xWin = 1
      if culmo == 4:
         oWin = 1
   if (xList[0][0] == "X" and xList[1][1] == "X" and xList[2][2] == "X" and xList[3][3] == "X") or (xList[0][3] == "X" and xList[1][2] == "X" and xList[2][1] == "X" and xList[3][0] == "X"):
      xWin = 1
   if (oList[0][0] == "O" and oList[1][1] == "O" and oList[2][2] == "O" and oList[3][3] == "O") or (oList[0][3] == "O" and oList[1][2] == "O" and oList[2][1] == "O" and oList[3][0] == "O"):
      oWin = 1

   if xWin == 1:
      outputList.append("X won")
   if oWin == 1:
      outputList.append("O won")
   if not((xWin == 1) or (oWin == 1)):
      dots = 0
      for x in range(4):
         if "." in xList[x]:
            dots = 1
      if dots == 0:
         outputList.append("Draw")
      else:
         outputList.append("Game has not completed")
   fp.readline()

fp.close()
outputString = ""
for x in range(len(outputList)):
   outputString += "Case #" + str(x + 1) + ": " + outputList[x] + "\n"

fp = open("output.txt", "w")
fp.write(outputString)
fp.close()
