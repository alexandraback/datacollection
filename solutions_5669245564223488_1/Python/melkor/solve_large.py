import itertools

MOD = 1000000007

def fact(x):
  res = 1
  for i in xrange(1,x+1):
    res *= i
    res = res %  MOD
  return res

def is_legal_perm(N, words, perm):
  words_perm = "".join([words[x] for x in perm])

  ch_set = set()

  cur_ch = words_perm[0]
  ch_set.add(cur_ch)

  for ch in words_perm[1:]:
    if ch == cur_ch:
      continue

    if ch in ch_set:
      return False

    ch_set.add(ch)
    cur_ch = ch

  return True
  

def count_legal_connections(N, words):
  counter = 0
  for perm in itertools.permutations(range(0,N)):
    if is_legal_perm(N, words, perm):
      counter += 1

  return counter

def short_word(x):
  new_word = ""

  cur_ch = None

  for i in xrange(len(x)):
   ch = x[i]
   if cur_ch:
     if ch != cur_ch:
       new_word += ch
       cur_ch = ch
   else:
     cur_ch = ch
     new_word += ch
  return new_word

def remove_dup_words(N, words):
  new_words = []
  dup_set = {}

  for word in words:
   if len(word) == 1:
     if word in dup_set.keys():
       dup_set[word] += 1
     else:
       dup_set[word] = 1
       new_words.append(word)

   else:
     new_words.append(word)

  factor = 1 
  for x in dup_set.keys():
    factor *= fact(dup_set[x])
    factor = factor % MOD
  return N, new_words, factor

def find_words_to_join(words_set, single_letter_words):
  for w1 in words_set:
    for w2 in words_set:
      if w1 != w2:
        if w1[-1] == w2[0]:
          if w1 not in single_letter_words and w2 not in single_letter_words and w1[-1] in single_letter_words:
           return True,w1,w2,short_word(w1+w2), str(w1[-1])
          else:
           return True,w1,w2,short_word(w1+w2), None
        if w2[-1] == w1[0]:
          if w1 not in single_letter_words and w2 not in single_letter_words and w2[-1] in single_letter_words:
            return True,w1,w2,short_word(w2+w1), str(w2[-1])
          else:
            return True,w1,w2,short_word(w2+w1), None
           
         
  return False, None,None,None,None

def try_to_join_words(N, words):
  words_set = words
  single_letter_words = set([w for w in words if len(w) == 1])
  flag,w1,w2,new_w,single_word_to_remove = find_words_to_join(words_set, single_letter_words)

  while flag:
    words_set.remove(w1)
    words_set.remove(w2)
    words_set.append(new_w)

    if w1 in single_letter_words:
      single_letter_words.remove(w1)

    if w2 in single_letter_words:
      single_letter_words.remove(w2)
  
    if single_word_to_remove:
      single_letter_words.remove(single_word_to_remove)
      words_set.remove(single_word_to_remove)

    flag,w1,w2,new_w,single_word_to_remove = find_words_to_join(words_set, single_letter_words)

  return len(words_set), list(words_set)

def has_conflicts(N, words):
  char_set = set()
  for word in words:
   for ch in word:
     if ch in char_set:
       return True
     char_set.add(ch)

  return False
     

if __name__ == '__main__':
  T = int(raw_input())

  for i in xrange(1,T+1):
   N = int(raw_input())
   words = tuple(x for x in raw_input().split())
   #print "Correct Case #%s: %s" % (i, count_legal_connections(N, words)) 
   words = [short_word(w) for w in words]
   assert len(words) == N


   if N == 1:
     if not has_conflicts(N, words):
       print "Case #%s: 1" % i
     else:
       print "Case #%s: 0" % i

     continue 
 
   new_N, words, factor = remove_dup_words(N, words)

   new_N, new_words = try_to_join_words(new_N,words)
   if has_conflicts(new_N, new_words):
     print "Case #%s: 0" % i 
   else:
     print "Case #%s: %s" % (i, (fact(new_N)*factor % MOD)) 
  

   
