import sys

def palindrome(num):
  num_str=str(num)
  num_len=len(num_str)
  for i in range(0, num_len / 2):
    if num_str[i] != num_str[num_len - i - 1]:
      return False
  return True

def gen_numbers(width):
  rv = []
  for i in range(1, 10**width):
    num_str = str(i)
    num_str = (width - len(num_str)) * '0' + num_str
    rv.append(num_str)
  return rv

def generate():
  middle=['', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
  rv = []
  for i in range(1, 10):
    rv.append(long(i))
  for width in range(1, 7):
    right_parts = gen_numbers(width)
    for right_str in right_parts:
      left_str = right_str[::-1]
      if left_str[0] != '0':
        for mm in middle:
          rv.append(long(left_str + mm + right_str))
  return rv

def find_fair(numbers):
  rv = []
  for num in numbers:
    square = long(num * num)
    if palindrome(square):
      rv.append(square)
  return rv

gen = generate()
fair = find_fair(gen)

T = int(sys.stdin.readline()[:-1])
for t in range(0, T):
  line = sys.stdin.readline()[:-1]
  parts = line.split(' ');
  A = long(parts[0])
  B = long(parts[1])
  R = 0
  for f in fair:
    if f >= A and f <= B:
      R += 1
  print 'Case #' + str(t + 1) + ': ' + str(R)
