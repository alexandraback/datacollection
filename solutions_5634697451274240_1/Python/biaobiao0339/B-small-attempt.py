import fileinput
import logging
logging.basicConfig(level=logging.DEBUG)

def find_answer(lines):
  ''' Find the answer for this question '''
  input_str = lines[0]
  strList = ['+', '-']
  import re
  input_str = re.sub(r'\++$','',input_str)
  result = 0
  while len(input_str)>0:
    result = result + 1
    if input_str[0] == '-':
      input_str = input_str[::-1]
      input_str = re.sub(r'\+', 'a', input_str)
      input_str = re.sub(r'-', '+', input_str)
      input_str = re.sub(r'a', '-', input_str)
    else:  
      for i in reversed(xrange(len(input_str)-1)):
        if input_str[i] == '+':
          input_str_start = input_str[:i]
          input_str_start = re.sub(r'\+', 'a', input_str_start)
          input_str_start = re.sub(r'-', '+', input_str_start)
          input_str_start = re.sub(r'a', '-', input_str_start)
          input_str = input_str_start + input_str[i+1:]
          break

    
    input_str = re.sub(r'\++$','',input_str)



  return str(result)  
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
