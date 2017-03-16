import fileinput
import logging
logging.basicConfig(level=logging.DEBUG)

def find_answer(lines):
  ''' Find the answer for this question '''
  num = int(lines[0])
  numList = ['0','1','2','3','4','5','6','7','8','9']
  lenOfList = 100
  result = ''
  if num == 0:
    result = 'INSOMNIA'
  else:  
    for i in xrange(1, lenOfList):
      if len(numList) == 0:
          result = new_num
          break  
      new_num = str(num * i)
      for j in xrange(0, len(new_num)):
        if new_num[j] in numList:
          numList.remove(new_num[j])
        
    if not result:
        result = 'INSOMNIA'
  return result

def main():
  ''' Parse the input lines '''
  lines = [l.strip() for l in fileinput.input()]
  # Solve your problem here
  logging.debug(lines)
  n_tests = int(lines[0])
  start_test = 1
  n_lines = 1
  for i in xrange(0, n_tests):
    tc = lines[start_test:start_test+n_lines]
    logging.debug(tc)
    n = find_answer(tc)
    print 'Case #{}: {}'.format(i+1, n)
    start_test += n_lines

if __name__ == '__main__':
  main()
