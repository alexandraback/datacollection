import fileinput
import logging
import math
logging.basicConfig(level=logging.DEBUG)

def find_answer(start_num):
  ''' Find the answer for this question '''
  rlist = []
  if start_num.count('1')%2 == 0:
    rlist = ['', '2', '', '2', '', '2','', '2', '']
    for i in xrange(10,1,-2):
      num = int(start_num,i)
      # print 'num ' + str(num)
      prime = True
      # print 'square_num ' + str(int(math.sqrt(num)))
      base_num = int(math.sqrt(num)) if int(math.sqrt(num))<100000 else 100000
      for j in xrange(3,base_num+1,2):
        if num%j == 0:
          rlist[i-2] = str(j)
          prime = False
          break
      if prime == True :
        return (False, '')
  else:
    return (False, '')

    # for i in xrange(10,1,-1):
    #   num = int(start_num,i)
    #   # print 'num ' + str(num)
    #   prime = True
    #   # print 'square_num ' + str(int(math.sqrt(num)))
    #   base_num = int(math.sqrt(num)) if int(math.sqrt(num))<100000 else 100000
    #   for i in xrange(3,base_num+1,2):
    #     if num%i == 0:
    #       rlist.append(str(i))
    #       prime = False
    #       break

    #   if prime == True :
    #     return (False, '')

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
