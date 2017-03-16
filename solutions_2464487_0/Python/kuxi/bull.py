import sys


def bull(r, t):
  lastBlack = r-1
  total = 0
  while t > 0:
    white = lastBlack + 1
    nextBlack = lastBlack + 2
    paint = nextBlack * nextBlack - white * white
    if t >= paint:
      total += 1
      t -= paint
      lastBlack = nextBlack
    else:
      break
  return total


if __name__ == "__main__":
  lines = sys.stdin.readlines()
  for i in range(1, len(lines)):
    line = lines[i].strip().split(' ')
    r = int(line[0])
    t = int(line[1])
    res = bull(r, t)
    print "Case #{}: {}".format(i, res)
