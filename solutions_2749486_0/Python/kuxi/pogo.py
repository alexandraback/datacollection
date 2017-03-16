import sys

def pogo(x, y):
  moves = ""
  while x != 0:
    if x < 0:
      moves += "EW"
      x += 1
    else:
      moves += "WE"
      x -= 1
  while y != 0:
    if y < 0:
      moves += "NS"
      y += 1
    else:
      moves += "SN"
      y -= 1
  return moves


if __name__ == "__main__":
  lines = sys.stdin.readlines()
  i = 1
  while i < len(lines):
    line = lines[i].strip().split(' ')
    x = int(line[0])
    y = int(line[1])
    moves = pogo(x, y)
    print "Case #{}: {}".format(i, moves)
    i += 1
