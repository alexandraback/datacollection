from solver import solver
from collections import Counter

CACHE = set()

def rec(topics, da, db):
    # Caching
    if topics in CACHE:
        return
    CACHE.add(topics)
    # Yield length
    yield len(topics)
    # Recursion
    for i, (a, b) in enumerate(topics):
        if da[a] >= 2 and db[b] >= 2:
            cda = da.copy()
            cda[a] -= 1
            cdb = db.copy()
            cdb[b] -= 1
            yield from rec(topics[:i] + topics[i+1:], da, db)

@solver(lines_per_case='dynamic')
def techno(lines):
    CACHE.clear()
    topics = tuple(tuple(line.split()) for line in lines)
    da = Counter(x for x, y in topics)
    db = Counter(y for x, y in topics)
    m = min(rec(topics, da, db))
    return len(topics) - m

if __name__ == '__main__':
    techno.from_cli()
