from itertools import product

def tuple_to_int(src):
  return int(''.join([str(i) for i in src]))

def is_fair_square(number):
  if str(number) != str(number)[::-1]:
    return False
  number_pow2 = pow(number, 2)
  if str(number_pow2) != str(number_pow2)[::-1]:
    return False
  return True

def power2(number):
  return pow(number, 2);

def create_table():
  table = map(power2, filter(is_fair_square, map(tuple_to_int, list(product(["0", "1", "2"], repeat=14)))))
  # Remove 0
  table.pop()
  # Add 9 after 1, 4
  table.insert(2, 9)
  return table

def execute_case(table):
  begin, end = [int(token) for token in raw_input().split()]
  return len([i for i in table if begin <= i and i <= end])

def main():
  table = create_table()
  for i in range(int(raw_input())):
    print 'Case #%d: %d' % (i+1, execute_case(table))

if __name__ == "__main__":
  main()
