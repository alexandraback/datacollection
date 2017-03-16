public class ValueAndIndex implements Comparable<ValueAndIndex> {
	    final long value;
	    final int index;

	    ValueAndIndex(long value, int index) {
	        this.value = value;
	        this.index = index;
	    }

	    @Override public int compareTo(ValueAndIndex other) {
	       // compare on value;
	        if (this.value < other.value) {
	            return -1;
	        } else if (this.value > other.value) {
	            return 1;
	        } else {
	            return 0;
	        }
	    }
	}