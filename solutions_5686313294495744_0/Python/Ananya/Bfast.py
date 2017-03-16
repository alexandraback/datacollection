from operator import mul

def is_in_first(word, topics):
  for t in topics:
    if word == t[0]:
      return True
  return False

def is_in_second(word, topics):
  for t in topics:
    if word == t[1]:
      return True
  return False

def is_fake(cur_topics, others):
  return is_in_first(cur_topics[0], others) and is_in_second(cur_topics[1], others)

def recur(topics, index):
  if (index >= len(topics)):
    return 0
  # Either cur index is a fake, or it is not
  cur_topic = topics[index]
  others = topics[:index] + topics[(index+1):]
  if is_fake(cur_topic, others):
    try1 = recur(others, index) + 1
  else:
    try1 = 0
  try2 = recur(topics, index+1)
  return max(try1, try2)

num_cases = int(raw_input())
for case in range(1,num_cases+1):
  num_topics = int(raw_input())
  topics = []
  for i in range(num_topics):
    s = raw_input().split(" ")
    topics = topics + [s]
  answer = recur(topics, 0)
  print("Case #%d: %d" % (case, answer))
