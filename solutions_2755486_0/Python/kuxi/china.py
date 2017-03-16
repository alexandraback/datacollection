import sys

#encoding:utf-8
#Created by Liang Sun on May, 6, 2013
#from http://liangsun.org/posts/a-python-implementation-of-segment-tree/
class SegmentTree(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.min_value = {}
        self.max_value = {}
        self.sum_value = {}
        self.len_value = {}
        self._init(start, end)

    def add(self, start, end, weight=1):
        if start < self.start or end > self.end:
            return False
        self._add(start, end, weight, self.start, self.end)
        return True

    def setlower(self, start, end, lower):
        if start < self.start or end > self.end:
            return False
        self._setlower(start, end, lower, self.start, self.end)
        return True

    def query_min(self, start, end):
        return self._query_min(start, end, self.start, self.end)

    def query_max(self, start, end):
        return self._query_max(start, end, self.start, self.end)

    def query_sum(self, start, end):
        return self._query_sum(start, end, self.start, self.end)

    def query_len(self, start, end):
        return self._query_len(start, end, self.start, self.end)

    """"""
    def _init(self, start, end):
        self.min_value[(start, end)] = 0
        self.max_value[(start, end)] = 0
        self.sum_value[(start, end)] = 0
        self.len_value[(start, end)] = 0
        if start < end:
            mid = start + (end - start) / 2
            self._init(start, mid)
            self._init(mid+1, end)

    def _add(self, start, end, weight, in_start, in_end):
        key = (in_start, in_end)
        if in_start == in_end:
            self.min_value[key] += weight
            self.max_value[key] += weight
            self.sum_value[key] += weight
            self.len_value[key] = 1 if self.sum_value[key] > 0 else 0
            return

        mid = in_start + (in_end - in_start) / 2
        if mid >= end:
            self._add(start, end, weight, in_start, mid)
        elif mid+1 <= start:
            self._add(start, end, weight, mid+1, in_end)
        else:
            self._add(start, mid, weight, in_start, mid)
            self._add(mid+1, end, weight, mid+1, in_end)
        self.min_value[key] = min(self.min_value[(in_start, mid)], self.min_value[(mid+1, in_end)])
        self.max_value[key] = max(self.max_value[(in_start, mid)], self.max_value[(mid+1, in_end)])
        self.sum_value[key] = self.sum_value[(in_start, mid)] + self.sum_value[(mid+1, in_end)]
        self.len_value[key] = self.len_value[(in_start, mid)] + self.len_value[(mid+1, in_end)]

    def _setlower(self, start, end, lower, in_start, in_end):
        key = (in_start, in_end)
        if in_start == in_end:
            self.min_value[key] = max(self.min_value[key], lower)
            self.len_value[key] = 1 if self.sum_value[key] > 0 else 0
            return

        mid = in_start + (in_end - in_start) / 2
        if mid >= end:
            self._setlower(start, end, lower, in_start, mid)
        elif mid+1 <= start:
            self._setlower(start, end, lower, mid+1, in_end)
        else:
            self._setlower(start, mid, lower, in_start, mid)
            self._setlower(mid+1, end, lower, mid+1, in_end)
        self.min_value[key] = min(self.min_value[(in_start, mid)], self.min_value[(mid+1, in_end)])
        self.max_value[key] = max(self.max_value[(in_start, mid)], self.max_value[(mid+1, in_end)])
        self.sum_value[key] = self.sum_value[(in_start, mid)] + self.sum_value[(mid+1, in_end)]
        self.len_value[key] = self.len_value[(in_start, mid)] + self.len_value[(mid+1, in_end)]

    def _query_max(self, start, end, in_start, in_end):
        if start == in_start and end == in_end:
            ans = self.max_value[(start, end)]
        else:
            mid = in_start + (in_end - in_start) / 2
            if mid >= end:
                ans = self._query_max(start, end, in_start, mid)
            elif mid+1 <= start:
                ans = self._query_max(start, end, mid+1, in_end)
            else:
                ans = max(self._query_max(start, mid, in_start, mid),
                        self._query_max(mid+1, end, mid+1, in_end))
        return ans

    def _query_min(self, start, end, in_start, in_end):
        if start == in_start and end == in_end:
            ans = self.min_value[(start, end)]
        else:
            mid = in_start + (in_end - in_start) / 2
            if mid >= end:
                ans = self._query_min(start, end, in_start, mid)
            elif mid+1 <= start:
                ans = self._query_min(start, end, mid+1, in_end)
            else:
                ans = min(self._query_min(start, mid, in_start, mid),
                        self._query_min(mid+1, end, mid+1, in_end))
        return ans

    def _query_sum(self, start, end, in_start, in_end):
        if start == in_start and end == in_end:
            ans = self.sum_value[(start, end)]
        else:
            mid = in_start + (in_end - in_start) / 2
            if mid >= end:
                ans = self._query_sum(start, end, in_start, mid)
            elif mid+1 <= start:
                ans = self._query_sum(start, end, mid+1, in_end)
            else:
                ans = self._query_sum(start, mid, in_start, mid) + self._query_sum(mid+1, end, mid+1, in_end)
        return ans

    def _query_len(self, start, end, in_start, in_end):
        if start == in_start and end == in_end:
            ans = self.len_value[(start, end)]
        else:
            mid = in_start + (in_end - in_start) / 2
            if mid >= end:
                ans = self._query_len(start, end, in_start, mid)
            elif mid+1 <= start:
                ans = self._query_len(start, end, mid+1, in_end)
            else:
                ans = self._query_len(start, mid, in_start, mid) + self._query_len(mid+1, end, mid+1, in_end)

        return ans

def getattacks(tribes):
  attacks = {}
  for tribe in tribes:
    t = tribe.split(' ')
    d = int(t[0])
    n = int(t[1])
    w = int(t[2])
    e = int(t[3])
    s = int(t[4])
    dd = int(t[5])
    dm = int(t[6])
    ds = int(t[7])

    for a in range(n):
      attack = (w, e, s)
      if d not in attacks:
        attacks[d] = [attack]
      else:
        attacks[d].append(attack)
      w += dm
      e += dm
      s += ds
      d += dd
  #{day: [(west, east, strength)]}
  return attacks

def success(tribes):
  stree = SegmentTree(-10000, 10000)
  allattacks = getattacks(tribes)
  skeys = sorted(allattacks.keys())
  successes = 0
  #print allattacks
  for day in skeys:
    #print "day", day
    attacks = allattacks[day]
    fix = []
    for attack in attacks:
      m = stree.query_min(attack[0]*2, attack[1]*2)
      if m < attack[2]:
        successes += 1
        fix.append((attack[0], attack[1], attack[2]))
        #print "attack success at {}, {} ({})".format(attack[0], attack[1], attack[2])
    for f in fix:
      stree.setlower(f[0]*2, f[1]*2, f[2])
      #print "fixing {}({}), {}({}) to {}".format(f[0], f[0]*2, f[1],f[1]*2, attack[2])
  return successes

if __name__ =="__main__":
  lines = sys.stdin.readlines()
  case = 1
  i = 1
  while i < len(lines):
    n = int(lines[i].strip())
    i += 1
    tribes = [l.strip() for l in lines[i:i+n]]
    res = success(tribes)
    print "Case #{}: {}".format(case, res)
    case += 1
    i += n
