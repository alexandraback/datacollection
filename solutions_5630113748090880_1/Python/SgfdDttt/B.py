in_file = "B-large.in"
case_counter = 0
N = 0
list_counter = 0
height_dict = dict()
for line in open(in_file, 'r'):
  if case_counter == 0:
    case_counter += 1
    continue
  numbers_str = line.strip('\n').split(" ")
  if len(numbers_str) == 1:
    height_dict.clear()
    N = int(numbers_str[0])
    list_counter = 0
  else:
    list_counter += 1
    for height in numbers_str:
      if height_dict.has_key(height):
        height_dict[height] = height_dict[height] + 1
      else:
        height_dict[height] = 1
    if list_counter == 2*N-1:
      answer_list = list()
      for key in height_dict:
        if height_dict[key] % 2 == 1:
          answer_list.append(int(key))
      answer_list.sort()
      answer_string = 'Case #' + str(case_counter) + ': ' + ' '.join(str(e) for e in answer_list)
      case_counter += 1
      print(answer_string)  
