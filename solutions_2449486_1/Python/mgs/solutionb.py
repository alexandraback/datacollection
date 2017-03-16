import numpy

fin = open("input.txt",'r')
fout = open("output.txt",'w')

T = int(fin.readline().strip())

for i_case in range(T):
  dim_str = fin.readline().strip()
  dim = [int(a) for a in dim_str.split(' ')]
  board_list = []
  for i in range(dim[0]):
    line = fin.readline().strip()
    board_list.append([int(a) for a in line.split(' ')])
  X = numpy.matrix(board_list)
  col_limit = X.max(0).repeat(dim[0],0)
  row_limit = X.max(1).repeat(dim[1],1)
  limit = numpy.minimum(col_limit,row_limit)
  impossible = numpy.greater(limit,X).max()
  if impossible:
    out="Case #"+str(i_case+1)+": NO\n"
  else:
    out="Case #"+str(i_case+1)+": YES\n"
  fout.write(out)

fin.close()
fout.close()

