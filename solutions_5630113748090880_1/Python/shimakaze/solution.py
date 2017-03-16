def solve(input_file):
  f = open(input_file, 'r')
  output_file = input_file.split('.')[0] + ".out"
  o = open(output_file, 'w')
  num_tests = int(f.readline())
  for nt in range(num_tests):
    N = int(f.readline().strip())
    papers = []
    for i in range(2*N - 1):
      papers.append(map(int, f.readline().split(' ')))
    print "Doing case %d \n" % (nt+1)
    # print papers
    sorted_arrays = []
    for i in range(N):
      # print i
      # print papers
      f1 = get_min(papers, i)
      papers.remove(f1)
      f2 = get_min(papers, i)
      if f2 and f2[i] == f1[i]:
        papers.remove(f2)
        sorted_arrays.append([f1, f2])
      else:
        sorted_arrays.append([f1])
    if papers != []:
      raise Exception
    grid = []
    for i in range(N):
      grid.append([0] * N)
    missingIndex = -1
    for i in range(len(sorted_arrays)):
      arrays = sorted_arrays[i]
      if len(arrays) == 1:
        missingIndex = i
        break
      #   if check_validity(grid, arrays[0], True, i):
      #     place_in_grid(grid, arrays[0], True, i)
      #   else:
      #     place_in_grid(grid, arrays[0], False, i)
      # else:
      #   if check_validity(grid, arrays[0], True, i) and check_validity(grid, arrays[1], False, i):
      #     place_in_grid(grid, arrays[0], True, i)
      #     place_in_grid(grid, arrays[1], False, i)
      #   elif check_validity(grid, arrays[0], False, i) and check_validity(grid, arrays[1], True, i):
      #     place_in_grid(grid, arrays[0], False, i)
      #     place_in_grid(grid, arrays[1], True, i)
      #   else:
      #     raise Exception
    ans = []
    for i in range(N):
      if i == missingIndex:
        ans.append(sorted_arrays[missingIndex][0][missingIndex])
        continue

      num1 = sorted_arrays[i][0][missingIndex]
      num2 = sorted_arrays[i][1][missingIndex]
      num3 = sorted_arrays[missingIndex][0][i]

      if num3 == num1:
        ans.append(num2)
      else:
        ans.append(num1)

    ans = ' '.join(map(str, ans))

    o.write("Case #%d: %s\n" % ((nt+1), ans))

def get_min(papers, index):
  if papers == []:
    return None
  minimum = min(papers, key = lambda x: x[index])
  return minimum

def check_validity(grid, line, is_row, index):
  if is_row:
    for i in range(len(line)):
      if grid[index][i] == 0:
        break
      elif grid[index][i] != line[i]:
        return False
    for i in range(len(line)):
      if grid[index-1][i] >= line[i]:
        return False
  else:
    for i in range(len(line)):
      if grid[i][index] == 0:
        break
      elif grid[i][index] != line[i]:
        return False
    for i in range(len(line)):
      if grid[i][index-1] >= line[i]:
        return False
  return True

def place_in_grid(grid, line, is_row, index):
  if is_row:
    for i in range(len(line)):
      grid[index][i] = line[i]
  else:
    for i in range(len(line)):
      grid[i][index] = line[i]

def is_equal(a1, a2):
  for i in range(len(a1)):
    if a1[i] != a2[i]:
      return False
  return True

solve('B-large.in')