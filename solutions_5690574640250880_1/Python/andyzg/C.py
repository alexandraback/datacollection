adj = [(-1, -1), (0, -1), (1, -1), (-1, 0), (1, 0), (-1, 1), (0, 1), (1, 1)]
topRight = [(0,-1),(-1,0), (-1,-1)]

def buildField(x, y, count):
  global topRight
  field = []
  safeCount = x*y - count
#  print(safeCount)
  for i in range(0, x):
     row = []
     for j in range(0, y):
       row.append("*")
     field.append(row)
  add = []
  queue = []
  queue.append((x-1, y-1))
  add.append((x-1,y-1))
  field[x-1][y-1] = "X"
  safeCount -= 1
  ai = 0
  bj = 0
  while safeCount > 0:
    i,j = queue.pop(0)
    for a,b in topRight:
      ai = a + i
      bj = b + j
      if 0 <= ai < x and 0 <= bj < y:
        if field[ai][bj] == "*":
          field[ai][bj] = "X"
          add.append((ai,bj))
          queue.append((ai,bj))
          safeCount -= 1
          if safeCount == 0:
            break 

  if ai == x-1 and (ai,bj) in add and not x == 1:
    x,y = add.pop(add.index((ai,bj))-1)
    field[x][y] = "*"
    field[ai-1][bj] = "X"
  elif bj == y-1 and (ai, bj) in add and not y == 1:
    x,y = add.pop(add.index((ai,bj))-1)
    field[x][y] = "*"
    field[ai][bj-1] = "X"
  return field

def noAdjacent(a, b, field, x, y):
  global adj
  for i, j in adj:
    ai = a + i
    bj = b + j
    if 0 <= ai < x and 0 <= bj < y:
      if field[ai][bj] == "*":
        return False
  return True

def fieldToString(field):
  str = ""
  for row in field:
    rowString = ''.join(row)
    str += rowString + "\n"
  return str

def checkField(x, y, count):
  global adj
  safe = x*y - count
  if safe <= 0:
    return "Impossible"

  queue = []
  field = buildField(x, y, count)

  print(fieldToString(field))
  queue.append((x-1, y-1))
  entry = 1
  field[x-1][y-1] = "."

  while queue:
    a, b = queue.pop(0)
    for i, j in adj:
      ai = i + a
      bj = j + b
      if 0 <= ai < x and 0 <= bj < y:
        if not field[ai][bj] == "*" and not field[ai][bj] == ".":
          field[ai][bj] = "."
          entry += 1
          if noAdjacent(ai, bj, field, x, y):
            queue.append((ai, bj))
  
  if not noAdjacent(x-1, y-1, field, x, y) and safe > 1:
    return "Impossible"  
  elif safe <= entry:
    field[x-1][y-1] = "c"
    return fieldToString(field)
  else:
    return "Impossible"

def main():
  input = open("input.in", "r").read().split("\n")
  output = open("output.out", "w")

  cases = input.pop(0)
  for i in range(0, int(cases)):
    data = map(int, input.pop(0).split(" "))
    ans = checkField(data[0], data[1], data[2])

    safe = data[0]*data[1] - data[2]
    print(str(i+1))
    if ans == "Impossible":
      output.write("Case #" + str(i+1) + ":\nImpossible " + "\n")
    else:
      output.write("Case #" + str(i+1) +  ":\n" + ans)

main()
