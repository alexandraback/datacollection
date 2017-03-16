import random
import time


def read_int(): return int(raw_input())
def read_string(): return raw_input().strip()


def parse_input():
  T = read_int()
  Ns = [[c=='+' for c in read_string()][::-1] for _ in xrange(T)]
  return {
    'T': T,
    'Ns': Ns,
  }


def do_flip(stack, idx):
  return stack[:idx] + [not x for x in reversed(stack[idx:])]


def find_flip_plus(stack):
  assert stack[-1]
  idx = len(stack) - 1
  while stack[idx - 1]:
    idx -= 1
  return idx


def remove_bottom(stack):
  idx = 0
  while idx<len(stack) and stack[idx]:
    idx += 1
  return stack[idx:]


def solve_case(stack):
  stack = remove_bottom(stack)
  i = 0
  while stack:
    if stack[-1]:
      stack = do_flip(stack, find_flip_plus(stack))
    else:
      stack = do_flip(stack, idx=0)
    stack = remove_bottom(stack)
    i += 1
  return i

def main():
  inputs = parse_input()
  for idx, N in enumerate(inputs['Ns']):
    print 'Case #%d: %s' % (idx+1, str(solve_case(N)))

if __name__ == '__main__':
  main()