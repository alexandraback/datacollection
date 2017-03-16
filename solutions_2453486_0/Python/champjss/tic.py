def count_char(row, char):
  return len([cell for cell in row if cell == char])

def find_winner(row):
  num_o = count_char(row, "O")
  num_x = count_char(row, "X")
  num_t = count_char(row, "T")
  if num_o + num_t >= 4:
    return "O"
  elif num_x + num_t >= 4:
    return "X"
  else:
    return None

def is_table_full(table):
  return sum([count_char(row, ".") for row in table]) <= 0

def execute_case(case_no):
  table = [list(raw_input()) for i in range(4)]
  line_winner = ([find_winner(row) for row in table]
    + [find_winner(row) for row in zip(*table)]
    + [find_winner([table[i][i] for i in range(4)])]
    + [find_winner([table[i][3-i] for i in range(4)])])
  if "O" in line_winner:
    answer = "O won"
  elif "X" in line_winner:
    answer = "X won"
  elif is_table_full(table):
    answer = "Draw"
  else:
    answer = "Game has not completed"
  print 'Case #%d: %s' % (case_no, answer)
  raw_input()

def main():
  for i in range(int(raw_input())):
    execute_case(i+1)

if __name__ == "__main__":
  main()
