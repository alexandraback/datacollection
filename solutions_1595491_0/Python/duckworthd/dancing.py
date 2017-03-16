import re
import string
import sys

def parse_line(line):
  line = [int(v) for v in re.split('\s+', line.strip())]
  n_surprising = line[1]
  lower_bound = line[2]
  scores = line[3:]
  return (n_surprising, lower_bound, scores)

def max_above_lower_bound(n_surprising, lower_bound, sum_scores):
  print 'seeking number of scores with max greater than {} and no more than {} surprises out of {} candidates'.format(lower_bound, n_surprising, sum_scores)

  # guess the most surprising scores possible for everyone
  score_candidates = [surprising_score(v) for v in sum_scores]
  print 'all score candidates: {}'.format(score_candidates)

  # remove groups where, even when surprising (or we tried to make it so 
  # but couldn't), their max doesn't exceed the lower bound
  new_score_candidates = []
  for scores in score_candidates:
    if max(scores) < lower_bound:
      print 'removing {} as its max doesnt reach the lower_bound when surprising'.format(scores)
      continue
    else:
      new_score_candidates.append(scores)
  score_candidates = new_score_candidates
  
  # if making a scores unsurprising still meets the lower
  # bound, make it so
  new_score_candidates = []
  for scores in score_candidates:
    if is_surprising(scores) and (max(scores)-1) >= lower_bound:
      print 'making {} unsurprising as its max will still meet the lower bound'.format(scores)
      scores = unsurprise(scores)
    new_score_candidates.append(scores)
  score_candidates = new_score_candidates

  # making alterations to whoever's left would decrease the number of 
  # googlers meeting the lower bound, so just keep removing surprising
  # ones till we're stuck
  while True:
    surprising_left = sum( 
        is_surprising(scores) 
        for scores in score_candidates 
    )
    if surprising_left <= n_surprising:
      break

    for i in range(len(score_candidates)):
      if is_surprising(score_candidates[i]):
        print '{} is surprising and we have to get rid of it'.format(score_candidates[i])
        score_candidates.pop(i)
        break

  print 'the {} following exceed lower_bound while keeping in the n_surprising limit: {}'.format(len(score_candidates), score_candidates)
  return len(score_candidates)

def is_surprising(scores):
  (i_min, i_max) = argmin(scores), argmax(scores)
  return scores[i_max] - scores[i_min] >= 2

def surprising_score(sum_score):
  '''Retrieve the 3 judges scores that give the maximal scoring'''
  scores = [sum_score/3 for i in range(3)]
  while sum(scores) < sum_score:
    scores[0] += 1
  # either [+0, +0, +0], [+1, +0, +0], or [+2, +0, +0]
  if scores[0] - scores[1] == 0 and scores[2] > 0:
    scores[0] += 1
    scores[2] -= 1
  # either [+1, +0, -1], [+1, +0, +0] or [+2, +0, +0]
  return scores

def unsurprise(scores):
  '''Turn a surprising score unsurprising'''
  (i_min, i_max) = argmin(scores), argmax(scores)
  scores[i_min] += 1
  scores[i_max] -= 1
  return scores


def argmax(vals):
  return sorted_with_key(vals)[-1][1]

def argmin(vals):
  return sorted_with_key(vals)[0][1]

def sorted_with_key(vals):
  keyed = [(v,i) for (i, v) in enumerate(vals)]
  return sorted(keyed)


with open(sys.argv[2], 'w') as f_out:
  with open(sys.argv[1]) as f_in:
    for (i,line) in enumerate(f_in):
      if i == 0:
        continue

      # parse line
      parsed = parse_line(line)

      # output
      result = max_above_lower_bound(*parsed)
      print 80*'-'
      print parsed
      print result

      f_out.write('Case #{}: {}\n'.format(i, result))
