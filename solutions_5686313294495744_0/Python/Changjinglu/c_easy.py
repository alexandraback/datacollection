
def explore(topics, real, fake, pos):
  if pos == len(topics):
    for fake_topic in fake:
      found = [ False, False ]
      for real_topic in real:
        for i in range(2):
          if fake_topic[i] == real_topic[i]:
            found[i] = True
      if False in found:
        return 0
    return len(fake)
  result = 0
  real.append(topics[pos])
  result = max(result, explore(topics, real, fake, pos + 1))
  fake.append(real.pop())
  result = max(result, explore(topics, real, fake, pos + 1))
  fake.pop()
  return result

num_cases = int(raw_input())
for case_index in range(1, num_cases + 1):
  n = int(raw_input())
  topics = [ tuple(raw_input().split()) for i in range(n) ]
  result = explore(topics, [], [], 0)
  print('Case #%d: %d' % (case_index, result))

