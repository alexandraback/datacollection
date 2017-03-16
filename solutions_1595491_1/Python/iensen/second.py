import sys
sys.stdin,sys.stdout= map(open, '2l_in.txt 2l_out.txt'.split(), 'r w'.split())
number_of_tests=int(raw_input())
def test(P,ac_sum,max_dif):
  for best_result in xrange(P,11):
            for first_result in xrange(max(0,best_result-max_dif),best_result+1):
                for second_result in xrange(max(0,best_result-max_dif),best_result+1):
                    if(best_result+first_result+second_result==ac_sum):
                        return True
  return False

for test_id in xrange(number_of_tests):
    int_row=map(int,raw_input().split())
    N=int(int_row[0])
    S=int(int_row[1])
    P=int(int_row[2])
    point_sums=[]
    for idx in xrange(3,3+N):
        point_sums.append(int_row[idx])
    answer=0
    for ac_sum in point_sums:
        if(test(P,ac_sum,1)):
            answer+=1
        else:
            if(S>0 and test(P,ac_sum,2)):
                S-=1
                answer+=1
    print 'Case #'+str(test_id+1)+": "+str(answer)
                            
sys.stdout.flush()
sys.stdout.close()
sys.stdin.close()
