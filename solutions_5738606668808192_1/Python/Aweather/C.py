import argparse

parser = argparse.ArgumentParser(description='Google Code Jam 2016')
parser.add_argument('fin')
parser.add_argument('fout')

args = parser.parse_args()

fin = args.fin
fout = args.fout

def coin_jam(N,J):
  ret = []
  primeli = primelist()
  for i in range(0,pow(2,N-2)):
    seq = num_to_binary(i,N-2)
    seq.append(1)
    seq.insert(0,1)
    print(seq)
    seq_string = [str(i) for i in seq]
    output_string = ''.join(seq_string) + ' '
    is_coin_jam = True  
    for j in range(2,11):
      num = binary_to_num_with_base(seq,j)

      divisor = is_not_prime(num,primeli)
      #print(num)
      #print(divisor)
      #print(j)
      if divisor:
        output_string += str(divisor) + ' '
      else:
        is_coin_jam = False
        break
    if is_coin_jam:
      ret.append(output_string)
      if len(ret) >= J:
        return ret
  return ret
  



def is_not_prime(num, primeli):
  for i in primeli:
    if num % i == 0:
      return i
  return False

def primelist():
  ret = [2]
  i = 3
  while i**2 < 10**8:
    for j in ret:
      isprime = True
      if i%j == 0:
        isprime = False
    if isprime:
      ret.append(i)
    i += 1
  return ret




def num_to_binary(n,w):
  li = []
  while(n>0):
    li.append(n % 2)
    n = n//2
  while (len(li) < w):
    li.append(0)
  li.reverse()
  #print(li)
  return li

def binary_to_num_with_base(li,b):
  ret = 0;
  for i in li:
    ret *= b
    ret += i
  return ret


with open(fin,'r') as input, open(fout,'w') as output:
  T = int(input.readline().rstrip('\n'))
  for i in range(0,T):
    s = input.readline().rstrip('\n')
    l = [int(i) for i in s.split(' ')]
    N = l[0]
    J = l[1]
    #print('Case #{}: {}\n'.format(i+1,last_num(n)))
    output.write('Case #{}:\n'.format(i+1))
    result = coin_jam(N,J)
    print(result)
    for ln in result:
      output.write('{}\n'.format(ln))