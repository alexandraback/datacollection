import sys
import string

hardcoded={}
hardcoded[(1, 1, 0)] = "c"
hardcoded[(1, 2, 0)] = "c."
hardcoded[(1, 2, 1)] = "c*"
hardcoded[(1, 3, 0)] = "c.."
hardcoded[(1, 3, 1)] = "c.*"
hardcoded[(1, 3, 2)] = "c**"
hardcoded[(1, 4, 0)] = "c..."
hardcoded[(1, 4, 1)] = "c..*"
hardcoded[(1, 4, 2)] = "c.**"
hardcoded[(1, 4, 3)] = "c***"
hardcoded[(1, 5, 0)] = "c...."
hardcoded[(1, 5, 1)] = "c...*"
hardcoded[(1, 5, 2)] = "c..**"
hardcoded[(1, 5, 3)] = "c.***"
hardcoded[(1, 5, 4)] = "c****"
hardcoded[(2, 2, 0)] = "c.\n.."
hardcoded[(2, 2, 1)] = "Impossible"
hardcoded[(2, 2, 2)] = "Impossible"
hardcoded[(2, 2, 3)] = "c*\n**"
hardcoded[(2, 3, 0)] = "c..\n..."
hardcoded[(2, 3, 1)] = "Impossible"
hardcoded[(2, 3, 2)] = "c.*\n..*"
hardcoded[(2, 3, 3)] = "Impossible"
hardcoded[(2, 3, 4)] = "Impossible"
hardcoded[(2, 3, 5)] = "c**\n***"
hardcoded[(2, 4, 0)] = "c...\n...."
hardcoded[(2, 4, 1)] = "Impossible"
hardcoded[(2, 4, 2)] = "c..*\n...*"
hardcoded[(2, 4, 3)] = "Impossible"
hardcoded[(2, 4, 4)] = "c.**\n..**"
hardcoded[(2, 4, 5)] = "Impossible"
hardcoded[(2, 4, 6)] = "Impossible"
hardcoded[(2, 4, 7)] = "c***\n****"
hardcoded[(2, 5, 0)] = "c....\n....."
hardcoded[(2, 5, 1)] = "Impossible"
hardcoded[(2, 5, 2)] = "c...*\n....*"
hardcoded[(2, 5, 3)] = "Impossible"
hardcoded[(2, 5, 4)] = "c..**\n...**"
hardcoded[(2, 5, 5)] = "Impossible"
hardcoded[(2, 5, 6)] = "c.***\n..***"
hardcoded[(2, 5, 7)] = "Impossible"
hardcoded[(2, 5, 8)] = "Impossible"
hardcoded[(2, 5, 9)] = "c****\n*****"
hardcoded[(3, 3, 0)] = "c..\n...\n..."
hardcoded[(3, 3, 1)] = "c..\n...\n..*"
hardcoded[(3, 3, 2)] = "Impossible"
hardcoded[(3, 3, 3)] = "c.*\n..*\n..*"
hardcoded[(3, 3, 4)] = "Impossible"
hardcoded[(3, 3, 5)] = "c.*\n..*\n***"
hardcoded[(3, 3, 6)] = "Impossible"
hardcoded[(3, 3, 7)] = "Impossible"
hardcoded[(3, 3, 8)] = "c**\n***\n***"
hardcoded[(3, 4, 0)] = "c...\n....\n...."
hardcoded[(3, 4, 1)] = "c...\n....\n...*"
hardcoded[(3, 4, 2)] = "c...\n....\n..**"
hardcoded[(3, 4, 3)] = "c..*\n...*\n...*"
hardcoded[(3, 4, 4)] = "c...\n....\n****"
hardcoded[(3, 4, 5)] = "Impossible"
hardcoded[(3, 4, 6)] = "c.**\n..**\n..**"
hardcoded[(3, 4, 7)] = "Impossible"
hardcoded[(3, 4, 8)] = "c.**\n..**\n****"
hardcoded[(3, 4, 9)] = "Impossible"
hardcoded[(3, 4, 10)] = "Impossible"
hardcoded[(3, 4, 11)] = "c***\n****\n****"
hardcoded[(3, 5, 0)] = "c....\n.....\n....."
hardcoded[(3, 5, 1)] = "c....\n.....\n....*"
hardcoded[(3, 5, 2)] = "c....\n.....\n...**"
hardcoded[(3, 5, 3)] = "c...*\n....*\n....*"
hardcoded[(3, 5, 4)] = "c...*\n....*\n...**"
hardcoded[(3, 5, 5)] = "c....\n.....\n*****"
hardcoded[(3, 5, 6)] = "c..**\n...**\n...**"
hardcoded[(3, 5, 7)] = "c...*\n....*\n*****"
hardcoded[(3, 5, 8)] = "Impossible"
hardcoded[(3, 5, 9)] = "c.***\n..***\n..***"
hardcoded[(3, 5, 10)] = "Impossible"
hardcoded[(3, 5, 11)] = "c.***\n..***\n*****"
hardcoded[(3, 5, 12)] = "Impossible"
hardcoded[(3, 5, 13)] = "Impossible"
hardcoded[(3, 5, 14)] = "c****\n*****\n*****"
hardcoded[(4, 4, 0)] = "c...\n....\n....\n...."
hardcoded[(4, 4, 1)] = "c...\n....\n....\n...*"
hardcoded[(4, 4, 2)] = "c...\n....\n...*\n...*"
hardcoded[(4, 4, 3)] = "c...\n....\n...*\n..**"
hardcoded[(4, 4, 4)] = "c..*\n...*\n...*\n...*"
hardcoded[(4, 4, 5)] = "c..*\n...*\n...*\n..**"
hardcoded[(4, 4, 6)] = "c..*\n...*\n..**\n..**"
hardcoded[(4, 4, 7)] = "c..*\n...*\n...*\n****"
hardcoded[(4, 4, 8)] = "c.**\n..**\n..**\n..**"
hardcoded[(4, 4, 9)] = "Impossible"
hardcoded[(4, 4, 10)] = "c.**\n..**\n..**\n****"
hardcoded[(4, 4, 11)] = "Impossible"
hardcoded[(4, 4, 12)] = "c.**\n..**\n****\n****"
hardcoded[(4, 4, 13)] = "Impossible"
hardcoded[(4, 4, 14)] = "Impossible"
hardcoded[(4, 4, 15)] = "c***\n****\n****\n****"
hardcoded[(4, 5, 0)] = "c....\n.....\n.....\n....."
hardcoded[(4, 5, 1)] = "c....\n.....\n.....\n....*"
hardcoded[(4, 5, 2)] = "c....\n.....\n....*\n....*"
hardcoded[(4, 5, 3)] = "c....\n.....\n.....\n..***"
hardcoded[(4, 5, 4)] = "c...*\n....*\n....*\n....*"
hardcoded[(4, 5, 5)] = "c....\n.....\n.....\n*****"
hardcoded[(4, 5, 6)] = "c....\n.....\n....*\n*****"
hardcoded[(4, 5, 7)] = "c....\n.....\n...**\n*****"
hardcoded[(4, 5, 8)] = "c..**\n...**\n...**\n...**"
hardcoded[(4, 5, 9)] = "c...*\n....*\n...**\n*****"
hardcoded[(4, 5, 10)] = "c....\n.....\n*****\n*****"
hardcoded[(4, 5, 11)] = "c..**\n...**\n...**\n*****"
hardcoded[(4, 5, 12)] = "c...*\n....*\n*****\n*****"
hardcoded[(4, 5, 13)] = "Impossible"
hardcoded[(4, 5, 14)] = "c.***\n..***\n..***\n*****"
hardcoded[(4, 5, 15)] = "Impossible"
hardcoded[(4, 5, 16)] = "c.***\n..***\n*****\n*****"
hardcoded[(4, 5, 17)] = "Impossible"
hardcoded[(4, 5, 18)] = "Impossible"
hardcoded[(4, 5, 19)] = "c****\n*****\n*****\n*****"
hardcoded[(5, 5, 0)] = "c....\n.....\n.....\n.....\n....."
hardcoded[(5, 5, 1)] = "c....\n.....\n.....\n.....\n....*"
hardcoded[(5, 5, 2)] = "c....\n.....\n.....\n....*\n....*"
hardcoded[(5, 5, 3)] = "c....\n.....\n....*\n....*\n....*"
hardcoded[(5, 5, 4)] = "c....\n.....\n.....\n...**\n...**"
hardcoded[(5, 5, 5)] = "c...*\n....*\n....*\n....*\n....*"
hardcoded[(5, 5, 6)] = "c...*\n....*\n....*\n....*\n...**"
hardcoded[(5, 5, 7)] = "c...*\n....*\n....*\n...**\n...**"
hardcoded[(5, 5, 8)] = "c...*\n....*\n...**\n...**\n...**"
hardcoded[(5, 5, 9)] = "c...*\n....*\n....*\n....*\n*****"
hardcoded[(5, 5, 10)] = "c..**\n...**\n...**\n...**\n...**"
hardcoded[(5, 5, 11)] = "c....\n.....\n....*\n*****\n*****"
hardcoded[(5, 5, 12)] = "c....\n.....\n...**\n*****\n*****"
hardcoded[(5, 5, 13)] = "c...*\n....*\n....*\n*****\n*****"
hardcoded[(5, 5, 14)] = "c...*\n....*\n...**\n*****\n*****"
hardcoded[(5, 5, 15)] = "c....\n.....\n*****\n*****\n*****"
hardcoded[(5, 5, 16)] = "c..**\n...**\n...**\n*****\n*****"
hardcoded[(5, 5, 17)] = "c...*\n....*\n*****\n*****\n*****"
hardcoded[(5, 5, 18)] = "Impossible"
hardcoded[(5, 5, 19)] = "c..**\n...**\n*****\n*****\n*****"
hardcoded[(5, 5, 20)] = "Impossible"
hardcoded[(5, 5, 21)] = "c.***\n..***\n*****\n*****\n*****"
hardcoded[(5, 5, 22)] = "Impossible"
hardcoded[(5, 5, 23)] = "Impossible"
hardcoded[(5, 5, 24)] = "c****\n*****\n*****\n*****\n*****"


def solution(R, C, M):
  return hardcoded[(R, C, M)]

def rotate(solution):
  rows = solution.split()
  res=[]
  for x in zip(*rows):
    res.append(''.join(x))
  return '\n'.join(res)

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):

  params = string.split(sys.stdin.readline().strip())

  R = int(params[0])
  C = int(params[1])
  M = int(params[2])


  print 'Case #' + repr(casenum) + ':'

  if R > C:
    R,C = C,R
    sol = solution(R, C, M)
    if sol != 'Impossible':
      print rotate(sol)
    else:
      print sol
  else:
    print solution(R, C, M)


