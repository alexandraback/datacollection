def print_lawn(lawn):
  for i in xrange(len(lawn)):
    for j in xrange(len(lawn[i])):
      print lawn[i][j],
    print "";  

def solve():
  N, M = map(int, raw_input().split())
  lawn = []
  for i in xrange(N):
    lawn.append(map(int,raw_input().split()))
  scores = dict()
  checked = [[False for x in xrange(M)] for x in xrange(N)]
  for i in xrange(len(lawn)):
    for j in xrange(len(lawn[i])):
      if lawn[i][j] not in scores:
	scores[lawn[i][j]] = []
      scores[lawn[i][j]].append((i,j))
  while len(scores) > 0:
    min_score = min(scores)
    #print min_score
    for tup in scores[min_score]:
      tup_i = tup[0]
      tup_j = tup[1]
      if not checked[tup_i][tup_j]:
	row_flag = True
	col_flag = True
	for j in xrange(M):
	  if(lawn[tup_i][j] > min_score):
	    row_flag = False
	    break;
	for i in xrange(N):
	  if(lawn[i][tup_j] > min_score):
	    col_flag = False
	    break;
	if not row_flag and not col_flag:
	  return "NO"
	if row_flag:
	  for j in xrange(M):
	    checked[tup_i][j] = True
	if col_flag:
	  for i in xrange(N):
	    checked[i][tup_j] = True	
    del scores[min_score]
  #print_lawn(lawn);
  return "YES"      

for i in xrange(input()):
  print "Case #%d: %s" % (i + 1, solve())
