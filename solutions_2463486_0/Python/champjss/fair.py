from math import sqrt, ceil, floor

def power2(number):
  return pow(number, 2);

def is_palindrome(number):
  return str(number) == str(number)[::-1]

def execute_case():
  begin, end = [int(token) for token in raw_input().split()]
  begin_base = int(ceil(sqrt(begin)))
  end_base = int(floor(sqrt(end)))
  return len(filter(is_palindrome, map(power2, filter(is_palindrome, range(begin_base, end_base+1)))))

def main():
  for i in range(int(raw_input())):
    print 'Case #%d: %d' % (i+1, execute_case())

if __name__ == "__main__":
  main()
