output = ""
steps = 0
def moveH(x):
  global output
  global steps
  s = "WE"
  if x < 0:
    s = "EW"
  for i in range(abs(x)):
    output += s
  steps += 2*abs(x)
def moveV(y):
  global output
  global steps
  s = "SN"
  if y < 0:
    s = "NS"
  for i in range(abs(y)):
    output += s
  steps += 2*abs(y)

for T in range(1, int(input())+1):
  X, Y = input().split()
  X, Y = int(X), int(Y)

  output = ""
  steps = 0
  if abs(X) <= abs(Y):
    moveH(X)
    if Y > 0:
      output += "N"
      steps += 1
      moveV(Y-steps)
    elif Y < 0:
      output += "S"
      steps += 1
      moveV(Y+steps)
  else:
    moveV(Y)
    if X > 0:
      output += "E"
      steps += 1
      moveH(X-steps)
    elif X < 0:
      output += "W"
      steps += 1
      moveH(X+steps)
  print("Case #%d: %s" % (T, output))
