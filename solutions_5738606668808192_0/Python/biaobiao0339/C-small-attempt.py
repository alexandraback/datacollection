import fileinput
import logging
import math
logging.basicConfig(level=logging.DEBUG)

def find_answer(start_num):
  ''' Find the answer for this question '''
  rlist = []
  for i in xrange(2,11):
    num = int(start_num,i)
    # print 'num ' + str(num)
    prime = True
    # print 'square_num ' + str(int(math.sqrt(num)))
    for i in xrange(2,int(math.sqrt(num))+1):
      if num%i == 0:
        rlist.append(str(i))
        prime = False
        break

    if prime == True :
      return (False, '')

  return (True, ' '.join(rlist))
           



def main():
  ''' Parse the input lines '''
  lines = [l.strip() for l in fileinput.input()]
  # Solve your problem here
  logging.debug(lines)
  print 'Case #1:'
  test_inputs = lines[1].split()
  num_len = int(test_inputs[0])
  req_len = int(test_inputs[1])
  # print 'num_len ' + str(num_len) 
  res_len = 0
  start_num = '1' + '0' * (num_len - 2) + '1'
  while res_len < req_len:
    # print 'start_num '+start_num
    isResult, rlist = find_answer(start_num)
    if isResult:
      print start_num + ' ' + rlist
      res_len += 1
    start_num = bin(int(start_num, 2) +2).replace('0b','')
    if len(start_num) > num_len:
      # print 'ERROR'
      return 

if __name__ == '__main__':
  main()
