def execute_case():
  num_row, num_col = [int(token) for token in raw_input().split()]
  table = [[int(cell) for cell in raw_input().split()] for i in range(num_row)]
  max_of_rows = [max(row) for row in table]
  max_of_cols = [max(col) for col in zip(*table)]
  for i in range(num_row):
    for j in range(num_col):
      if table[i][j] < max_of_rows[i] and table[i][j] < max_of_cols[j]:
        return 'NO'
  return 'YES'

def main():
  for i in range(int(raw_input())):
    print 'Case #%d: %s' % (i+1, execute_case())

if __name__ == "__main__":
  main()
