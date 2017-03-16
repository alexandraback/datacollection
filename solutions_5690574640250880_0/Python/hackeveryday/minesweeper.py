import sys
import functools


def cached(func):
  ''' Decorator for memorizted functions. '''
  mem = {}

  def template(*args):
    key = args
    try:
      ret = mem[key]
    except KeyError:
      ret = func(*args)
      mem[key] = ret
    else:
      pass
    return ret

  functools.update_wrapper(template, func)
  return template


def get_number_of_tests(fd):
  ''' get the number of tests. '''
  n = fd.readline()
  return int(n)


def get_r_c_m(fd):
  ''' get r, c, m. '''
  line = fd.readline()
  return map(int, line.strip().split())


def neighbors(rmax, cmax, pr, pc):
  ''' get neighbors around (pr, pc) '''
  for dr in (-1, 0, 1):
    for dc in (-1, 0, 1):
      if dr == 0 and dc == 0:
        continue
      r = pr + dr
      if r < 0:
        continue
      c = pc + dc
      if c < 0:
        continue
      if r >= rmax:
        continue
      if c >= cmax:
        continue
      yield (r, c)


def new_neighbors(rmax, cmax, pr, pc, empties):
  ''' get new neighbors around pr, pc '''
  for n in neighbors(rmax, cmax, pr, pc):
    if n not in empties:
      yield n


@cached
def search(rmax, cmax, target_empty, px, py, boundaries, empties):
  if len(empties) == target_empty:
    return empties
  elif len(empties) > target_empty:
    return None
  else:
    try:
      ns = set(new_neighbors(rmax, cmax, px, py, empties))
      boundaries_copy = set(boundaries)
      boundaries_copy = boundaries_copy.union(ns)
      for p in boundaries_copy:
        new_boundaries = boundaries_copy.copy()
        new_boundaries.remove(p)
        searched = search(rmax, cmax,
                          target_empty, p[0], p[1],
                          frozenset(new_boundaries), frozenset(empties.union(ns)))
        if searched:
          return searched
    except Exception:
      pass


def get_empties(rmax, cmax, mines):
  grids = rmax * cmax
  empty = grids - mines
  if empty <= 0:
    return None
  if empty == grids:
    return ((r, c) for r in xrange(rmax) for c in xrange(cmax))
  boundaries = [(0, 0)]
  empties = frozenset(boundaries)
  if empty == 1:
    return empties
  return search(rmax, cmax, empty, 0, 0, frozenset(), empties)


def render_grids(rows, cols, empties, click):
  grids = [list('*' * cols) for r in xrange(rows)]
  for r, c in empties:
    grids[r][c] = '.'
  r, c = click
  grids[r][c] = 'c'
  return '\n'.join(map(''.join, grids))


def main(fd):
  n = get_number_of_tests(fd)
  for i in xrange(n):
    r, c, m = get_r_c_m(fd)
    empties = get_empties(r, c, m)
    print 'Case #%d:' % (i + 1)
    if empties:
      print render_grids(r, c, empties, (0, 0))
    else:
      print 'Impossible'

if __name__ == '__main__':
  main(sys.stdin)
