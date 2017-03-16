import sys
import math

def main():
  infd = open(sys.argv[1])
  outfd = open(sys.argv[1] + '.out', 'w')
  T = int(infd.readline())
  for case in range(1, T+1):
    K,L,S = map(int, infd.readline().split())
    keyboard = infd.readline().strip()
    target = infd.readline().strip()
    expected = solve(K,L,S,keyboard,target)
    outfd.write('Case #' + str(case) + ': ')
    outfd.write(str(expected) + '\n')
  infd.close()
  outfd.close()

def solve(k,l,s,keyboard,target):
  keyboard_letters = set(ch for ch in keyboard)
  for ch in target:
    if ch not in keyboard_letters:
      return 0.0
  max_bananas = get_max_bananas(s, target)
  likely_bananas = get_likely_bananas(k,l,s,keyboard,keyboard_letters,target)
  return max_bananas - likely_bananas

def get_max_bananas(s, target):
  restart = len(target)
  for i in range(1, len(target)):
    left = len(target) - i
    if target[:left] == target[i:]:
      restart = len(target) - left
      break
  return 1 + int(math.floor( (s - len(target)) / restart))

def get_likely_bananas(k,l,s, keyboard, keyboard_letters, target):
  letter_prob = {}
  for let in keyboard_letters:
    letter_prob[let] = float(num_occs(let, keyboard)) / len(keyboard)
  sum = 1
  for let in target:
    sum *= letter_prob[let]
  sum = sum * (s - l + 1)
  return sum

def num_occs(ch, word):
  sum = 0
  for let in word:
    if let == ch:
      sum += 1
  return sum

if __name__ == '__main__':
  main()


