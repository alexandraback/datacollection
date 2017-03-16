#!/usr/bin/env python

import heapq
import sys


class State(object):
    order = 0

    def __init__(self, stack, cost):
        self.stack = stack
        self.cost = cost
        self.order = State.order
        self.extra = None
        State.order += 1

    def correct(self):
        return False not in self.stack

    def estimate(self):
        # At least one flip for every transition?
        if self.extra is None:
            self.extra = not self.stack[-1]
            for i in xrange(len(self.stack) - 1, 0, -1):
               if self.stack[i - 1] != self.stack[i]:
                   self.extra += 1
        return self.cost + self.extra

    def __cmp__(self, other):
        c = cmp(self.estimate(), other.estimate())
        if c:
            return c
        return cmp(other.order, self.order)

    def __repr__(self):
        return "State(state=%s, cost=%s, order=%s)" % (
            self.stack, self.cost, self.order)

    def step(self):
        result = []
        for i in range(1, len(self.stack) + 1):
            new_stack = (list(reversed([not j for j in self.stack[:i]])) +
                         self.stack[i:])
            result.append(State(new_stack, self.cost + 1))
        return result


def solve(stack):
    if False not in stack:
        return 0
    queue = [State(stack, 0)]
    if queue[0].correct():
        return 0
    best = sys.maxint
    while queue:
        state = heapq.heappop(queue)
        if state.estimate() > best:
            break
        # For each split point, flip the stack.
        for step in state.step():
            if step.correct():
                best = min(best, step.cost)
                continue
            heapq.heappush(queue, step)

    return best


def main():
    lines = sys.stdin.readlines()
    tests = int(lines[0])
    for i in xrange(tests):
        stack = [True if c == "+" else False for c in lines[i + 1][:-1]]
        print "Case #%d: %d" % (i + 1, solve(stack))


if __name__ == "__main__":
    main()
