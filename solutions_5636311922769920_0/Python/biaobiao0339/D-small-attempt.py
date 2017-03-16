import fileinput
import logging
import re
import math
logging.basicConfig(level=logging.DEBUG)

def find_answer(lines):
  ''' Find the answer for this question '''
  params = lines[0].split(' ')
  k_len = int(params[0])
  # print k_len
  c_deep = int(params[1])
  limit = int(params[2])
  
  if k_len <= limit:
    return ' '.join([str(i+1) for i in xrange(0, k_len)])



  props = int(math.pow(2,k_len))
  # print 'props'
  # print str(props)
  final_len = int(math.pow(k_len, c_deep))
  if final_len > 500:
    result_list = [0] * 500
    for i in xrange(0, int((final_len - 500)/10+2)):
      buffer_array = [0] * 500
      result_list.append(result_list)
  else:
    result_list = [0] * final_len

  for prop in xrange(1, props - 1):
    t_str = bin(prop).zfill(k_len + 2).replace('0b','')
    # print 'l test:' + t_str
    l_list = [m.start() for m in re.finditer('1', t_str)]
    # print 'l_list'
    # print l_list
    new_list = []
    if c_deep == 1:
      for j in l_list:
        result_list[j] += 1
      # print 'final_str:'
      # print result_list
    else:

      for i in xrange(1, c_deep):

        if len(new_list)<=0:
          res_list = list(l_list)
        else :
          res_list = new_list  
        new_list = []
        if i == c_deep-1:
          for j in res_list:
            for k in l_list:
              new_pos = j * k_len + k
              result_list[new_pos] += 1
          # print 'final_str:'
          # print result_list
        else:
          for j in res_list:
            for k in l_list:
              new_pos = j * k_len + k
              new_list.append(new_pos)
  can_try = 0
  try_list = []
  group_result = {}         
  for i, v in enumerate(result_list):
    # print i,v
    # print group_result
    if not v in group_result:
      group_result[v] = [str(i+1)]
    else:  
      group_result[v].append(str(i+1))
    # print group_result[v]


  # print 'group_result'
  # print group_result
  for k, v in group_result.items():
    if k < limit:
      if len(v) > k:
        return ' '.join(v[:k+1])
    else: 
      break      
  return 'IMPOSSIBLE'                    

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
