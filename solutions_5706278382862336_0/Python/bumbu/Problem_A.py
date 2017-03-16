import string
from fractions import Fraction

# _file = open("./test.txt")
_file = open("./A-small-attempt0.in")
_result = open("./result.txt", "w")

dataset_size = int(_file.readline())
case = 0

for i in range(dataset_size):
  case += 1

  upper, lower = map(lambda x: int(x), _file.readline().replace("\n", "").split('/'))
  # print upper, lower

  divider = 1
  first = 0
  for i in range(1, 42):
    divider *= 2
    # print 'd', divider
    if upper * divider >= lower:
      upper = upper * divider - lower
      lower = lower * divider

      if first == 0:
        first = i

      if upper == 0:
        break
      else:
        fr = Fraction(upper, lower)
        upper, lower = fr.numerator, fr.denominator

  if i < 41:
    result = "Case #" + str(case) + ": " + str(first)
  else:
    result = "Case #" + str(case) + ": impossible"

  print result
  _result.write(result + "\n")

_file.close()
_result.close()
