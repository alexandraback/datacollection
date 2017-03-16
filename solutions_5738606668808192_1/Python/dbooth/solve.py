#python 2.7

import sys
import math
import string
import time

#https://stackoverflow.com/questions/2267362/convert-integer-to-a-string-in-a-given-numeric-base-in-python
digs = string.digits + string.letters

def int2base(x, base):
  if x < 0: sign = -1
  elif x == 0: return digs[0]
  else: sign = 1
  x *= sign
  digits = []
  while x:
    digits.append(digs[x % base])
    x /= base
  if sign < 0:
    digits.append('-')
  digits.reverse()
  return ''.join(digits)

#https://stackoverflow.com/questions/1801391/what-is-the-best-algorithm-for-checking-if-a-number-is-prime
def isprime(n, time_limit):
    """Returns True if n is prime."""
    if n == 2:
        return True
    if n == 3:
        return True
    if n % 2 == 0:
        return 2
    if n % 3 == 0:
        return 3

    i = 5
    w = 2
    counter = 0
    while i * i <= n:
        if n % i == 0:
            return i

        i += w
        w = 6 - w
        counter += 1
        if (counter % 100000) == 0:
            if time.time() > time_limit:
                print "Skipping " + str(n) + " due to time limit heuristic. C:" + str(counter)
                return True 
                

    return True

def solve(J, N, output_file):
    min_valid = "1" + "0"*(N-2) + "1"
    max_valid = int("1"*N)
    print "Min valid: " + min_valid
    cur_value = int(min_valid, 2)

    jamcoins = list()
    while cur_value <= max_valid:
        cur_bin_str = int2base(cur_value, 2)
        cur_value += 0b10
        divisors = list()
        for i in range(2,11):
            divisor = isprime(int(cur_bin_str, i), time.time() + .05)
            if (divisor == True):
	        print cur_bin_str + " has 'prime' at base " + str(i)
                break
            divisors.append(divisor)
        else:
            divisors_str = ""
            for div in divisors:
                divisors_str += str(div) + " "
            print cur_bin_str + " " + divisors_str.strip() 
            output_file.write(cur_bin_str + " " + divisors_str.strip() + "\n")
            jamcoins.append([cur_bin_str, divisors])
            if len(jamcoins) == J:
                print "SUCCESS"
                return
            

def main():
    if (not len(sys.argv) == 3):
        print("Need exactly twos args: input filename and output filename")
        return
    input_data = open(sys.argv[1], 'r').read()
    output_file = open(sys.argv[2], 'w')
    split_input = input_data.split("\n")
    N,J = split_input[1].split(" ")
    output_file.write("Case #1\n")
    case_count = int(split_input[0])
    for i in range(0,case_count):
        res = solve(int(J),int(N), output_file)
    
if __name__ == "__main__":
    main()
