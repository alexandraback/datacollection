public class State {
    String pattern;
    int previous;

    public State(String pattern, int previous) {
        this.pattern = pattern;
        this.previous = previous;
    }

    @Override
    public int hashCode() {
        return pattern.hashCode() * 31 + previous;
    }

    @Override
    public boolean equals(Object obj) {
        return obj != null && (obj.getClass().equals(State.class) && ((State) obj).pattern == pattern && ((State) obj).previous == previous);
    }
}