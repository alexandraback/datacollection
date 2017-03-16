import sys


def FairSquare(upper_bound):
  answers = set([])
  for left_part in range(1000):
    for center_digit in range(10):
      palindrome = long(str(left_part) + str(center_digit) + str(left_part)[::-1])
      if left_part == 0:
        palindrome = center_digit
      if palindrome == 0:
        continue      
      square = palindrome * palindrome
      if square <= upper_bound and str(square) == str(square)[::-1]:
        #print palindrome, square
        answers.add(square)
    palindrome = long(str(left_part) + str(left_part)[::-1])
    if palindrome == 0:
      continue
    square = palindrome * palindrome
    if square <= upper_bound and str(square) == str(square)[::-1]:
      #print palindrome, square
      answers.add(square)
  return answers


def main():
  all_answers = FairSquare(long("100000000000000"))
  fin = open("C.in", "r")
  fout = open("C.out", "w")
  tests = int(fin.readline())
  for test_index in range(tests):
    (A, B) = map(int, fin.readline().strip().split(" "))
    if test_index % 100 == 0:
      print A, B
    result = 0
    for x in all_answers:
      if x >= A and x <= B:
        result = result + 1
    fout.write("Case #%d: " % (test_index + 1) + str(result) + "\n")
    if test_index % 100 == 0:
      print result
  fin.close()
  fout.close()


if __name__ == '__main__':
  main()